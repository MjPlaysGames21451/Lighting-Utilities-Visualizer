#include "LightingUtilitiesEditorSubsystem.h"
#include "Editor.h"
#include "Editor/UnrealEdEngine.h"
#include "UnrealEdGlobals.h"
#include "HAL/FileManager.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Engine/World.h"
#include "Engine/LevelStreaming.h"
#include "Engine/StaticMeshActor.h"
#include "EngineUtils.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

DEFINE_LOG_CATEGORY_STATIC(LogLightingUtils, Log, All);

void ULightingUtilitiesEditorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    UE_LOG(LogLightingUtils, Display, TEXT("[LightingUtilities] Subsystem Initialized. (Preview inactive until Applied)"));

    FEditorDelegates::OnMapOpened.AddUObject(this, &ULightingUtilitiesEditorSubsystem::OnMapOpened);
    FEditorDelegates::PreSaveWorld.AddUObject(this, &ULightingUtilitiesEditorSubsystem::OnPreSaveWorld);
    FEditorDelegates::PostSaveWorld.AddUObject(this, &ULightingUtilitiesEditorSubsystem::OnPostSaveWorld);

    ReloadData();
}

void ULightingUtilitiesEditorSubsystem::Deinitialize()
{
    FEditorDelegates::OnMapOpened.RemoveAll(this);
    FEditorDelegates::PreSaveWorld.RemoveAll(this);
    FEditorDelegates::PostSaveWorld.RemoveAll(this);

    ClearPreview();
    Super::Deinitialize();
}

UWorld* ULightingUtilitiesEditorSubsystem::GetSafeEditorWorld() const
{
    if (!GEditor)
    {
        return nullptr;
    }

    for (const FWorldContext& Context : GEditor->GetWorldContexts())
    {
        if (Context.WorldType == EWorldType::Editor && Context.World())
        {
            return Context.World();
        }
    }

    return nullptr;
}

TArray<FString> ULightingUtilitiesEditorSubsystem::GetAvailableUtilityMaps()
{
    TArray<FString> FoundMaps;
    TArray<FString> FileList;

    IFileManager::Get().FindFilesRecursive(FileList, *FPaths::ProjectContentDir(), TEXT("*LightingUtilities*.umap"), true, false);

    for (const FString& FilePath : FileList)
    {
        FString PackagePath;
        if (FPackageName::TryConvertFilenameToLongPackageName(FilePath, PackagePath))
        {
            FoundMaps.AddUnique(PackagePath);
        }
    }

    const FString DefaultMap = TEXT("/Game/Maps/World/MAP_LightingUtilities");
    if (!FoundMaps.Contains(DefaultMap))
    {
        FoundMaps.Insert(DefaultMap, 0);
    }
    else
    {
        FoundMaps.Remove(DefaultMap);
        FoundMaps.Insert(DefaultMap, 0);
    }

    return FoundMaps;
}

void ULightingUtilitiesEditorSubsystem::SetSelectedUtilityMap(const FString& InMapPackage)
{
    if (TargetUtilityPackage == InMapPackage)
    {
        return;
    }

    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Active Utility Map changed to: '%s'"), *InMapPackage);
    TargetUtilityPackage = InMapPackage;

    LastUmapTimestamp = FDateTime::MinValue();
    LastUexpTimestamp = FDateTime::MinValue();

    ReloadData();

    if (bIsPreviewActive)
    {
        RefreshLighting(true);
    }
}

TArray<FString> ULightingUtilitiesEditorSubsystem::GetAllActiveMapAndSublevelNames(UWorld* World) const
{
    TArray<FString> LevelNames;
    if (!World)
    {
        return LevelNames;
    }

    // 1. Persistent Level
    FString PersistentPackage = World->GetOutermost()->GetName();
    LevelNames.Add(PersistentPackage);
    LevelNames.Add(FPackageName::GetShortName(PersistentPackage));

    // 2. Loaded Sublevels
    for (ULevel* Level : World->GetLevels())
    {
        if (Level && Level->GetOutermost())
        {
            FString LevelPackage = Level->GetOutermost()->GetName();
            LevelNames.AddUnique(LevelPackage);
            LevelNames.AddUnique(FPackageName::GetShortName(LevelPackage));
        }
    }

    // 3. Streaming Level definitions
    for (ULevelStreaming* StreamingLevel : World->GetStreamingLevels())
    {
        if (StreamingLevel)
        {
            FString StreamPackage = StreamingLevel->GetWorldAssetPackageName();
            if (!StreamPackage.IsEmpty())
            {
                LevelNames.AddUnique(StreamPackage);
                LevelNames.AddUnique(FPackageName::GetShortName(StreamPackage));
            }
        }
    }

    return LevelNames;
}

void ULightingUtilitiesEditorSubsystem::OnMapOpened(const FString& Filename, bool bAsTemplate)
{
    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Map Opened: %s"), *Filename);
    LastAppliedSignature.Empty();

    if (bIsPreviewActive)
    {
        RefreshLighting(true);
    }
}

void ULightingUtilitiesEditorSubsystem::Tick(float DeltaTime)
{
    TimeSinceLastCheck += DeltaTime;
    if (TimeSinceLastCheck < CheckInterval)
    {
        return;
    }
    TimeSinceLastCheck = 0.0f;

    const bool bFilesChanged = CheckForFileUpdates();
    if (bFilesChanged)
    {
        UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Disk file change detected! Reloading..."));
        ReloadData();
    }

    if (!bIsPreviewActive)
    {
        return;
    }

    UWorld* World = GetSafeEditorWorld();
    if (!World)
    {
        return;
    }

    TArray<FString> ActiveLevels = GetAllActiveMapAndSublevelNames(World);
    FString CurrentSignature = FString::Join(ActiveLevels, TEXT("|")) + FString::Printf(TEXT("_Mode%d"), (int32)CurrentLightingMode);

    if (CurrentSignature != LastAppliedSignature)
    {
        RefreshLighting(true);
    }
}

bool ULightingUtilitiesEditorSubsystem::CheckForFileUpdates()
{
    bool bUpdated = false;
    IFileManager& FileManager = IFileManager::Get();

    FString UmapDiskPath = FPackageName::LongPackageNameToFilename(TargetUtilityPackage, TEXT(".umap"));
    if (FileManager.FileExists(*UmapDiskPath))
    {
        FDateTime UmapTime = FileManager.GetTimeStamp(*UmapDiskPath);
        if (LastUmapTimestamp != FDateTime::MinValue() && UmapTime > LastUmapTimestamp)
        {
            bUpdated = true;
        }
        LastUmapTimestamp = UmapTime;
    }

    FString UexpDiskPath = FPackageName::LongPackageNameToFilename(TargetUtilityPackage, TEXT(".uexp"));
    if (FileManager.FileExists(*UexpDiskPath))
    {
        FDateTime UexpTime = FileManager.GetTimeStamp(*UexpDiskPath);
        if (LastUexpTimestamp != FDateTime::MinValue() && UexpTime > LastUexpTimestamp)
        {
            bUpdated = true;
        }
        LastUexpTimestamp = UexpTime;
    }

    FString ShortMapName = FPackageName::GetShortName(TargetUtilityPackage);
    TArray<FString> JsonCandidates;
    JsonCandidates.Add(FPaths::ProjectPluginsDir() / FString::Printf(TEXT("LightingUtilitiesEditor/Content/LightingUtilities/%s.json"), *ShortMapName));
    JsonCandidates.Add(FPaths::ProjectPluginsDir() / TEXT("LightingUtilitiesEditor/Content/LightingUtilities/MAP_LightingUtilities.json"));

    for (const FString& JsonPath : JsonCandidates)
    {
        if (FileManager.FileExists(*JsonPath))
        {
            FDateTime JsonTime = FileManager.GetTimeStamp(*JsonPath);
            if (LastJsonTimestamp != FDateTime::MinValue() && JsonTime > LastJsonTimestamp)
            {
                bUpdated = true;
            }
            LastJsonTimestamp = JsonTime;
            break;
        }
    }

    return bUpdated;
}

void ULightingUtilitiesEditorSubsystem::ReloadData()
{
    CachedJsonEntries.Empty();
    IFileManager& FileManager = IFileManager::Get();

    FString ShortMapName = FPackageName::GetShortName(TargetUtilityPackage);

    TArray<FString> PotentialJsonPaths;
    PotentialJsonPaths.Add(FPaths::ProjectPluginsDir() / FString::Printf(TEXT("LightingUtilitiesEditor/Content/LightingUtilities/%s.json"), *ShortMapName));
    PotentialJsonPaths.Add(FPaths::ProjectContentDir() / FString::Printf(TEXT("LightingUtilities/%s.json"), *ShortMapName));
    PotentialJsonPaths.Add(FPaths::ProjectPluginsDir() / TEXT("LightingUtilitiesEditor/Content/LightingUtilities/MAP_LightingUtilities.json"));
    PotentialJsonPaths.Add(FPaths::ProjectContentDir() / TEXT("LightingUtilities/MAP_LightingUtilities.json"));

    FString FoundJsonPath;
    for (const FString& Path : PotentialJsonPaths)
    {
        if (FileManager.FileExists(*Path))
        {
            FoundJsonPath = Path;
            break;
        }
    }

    if (!FoundJsonPath.IsEmpty())
    {
        FString JsonContent;
        if (FFileHelper::LoadFileToString(JsonContent, *FoundJsonPath))
        {
            TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonContent);
            if (FJsonSerializer::Deserialize(Reader, CachedJsonEntries))
            {
                UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Loaded %d JSON entries from '%s'."),
                    CachedJsonEntries.Num(), *FoundJsonPath);
            }
        }
    }

    if (bIsPreviewActive)
    {
        RefreshLighting(true);
    }
}

void ULightingUtilitiesEditorSubsystem::ApplyLighting()
{
    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] ApplyLighting triggered! Activating preview."));
    bIsPreviewActive = true;
    RefreshLighting(true);
}

void ULightingUtilitiesEditorSubsystem::SetCurrentLightingMode(ELightingUtilityMode InMode)
{
    CurrentLightingMode = InMode;
    bIsPreviewActive = true;
    RefreshLighting(true);
}

void ULightingUtilitiesEditorSubsystem::SetLightingMode()
{
    bIsPreviewActive = true;
    RefreshLighting(true);
}

void ULightingUtilitiesEditorSubsystem::RefreshLighting(bool bForce)
{
    if (!bIsPreviewActive)
    {
        return;
    }

    UWorld* World = GetSafeEditorWorld();
    if (!World || World->IsPlayInEditor())
    {
        return;
    }

    TArray<FString> ActiveLevels = GetAllActiveMapAndSublevelNames(World);
    FString CurrentSignature = FString::Join(ActiveLevels, TEXT("|")) + FString::Printf(TEXT("_Mode%d"), (int32)CurrentLightingMode);

    if (!bForce && CurrentSignature == LastAppliedSignature)
    {
        return;
    }

    LastAppliedSignature = CurrentSignature;
    ApplyMeshMaterialsForActiveLevels();
}

UMaterialInterface* ULightingUtilitiesEditorSubsystem::ResolveMaterialFromObjectPath(const FString& ObjectPath)
{
    if (ObjectPath.IsEmpty())
    {
        return nullptr;
    }

    if (UMaterialInterface** FoundMat = LoadedMaterialCache.Find(ObjectPath))
    {
        return *FoundMat;
    }

    UMaterialInterface* Mat = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, *ObjectPath));
    if (Mat)
    {
        LoadedMaterialCache.Add(ObjectPath, Mat);
    }
    return Mat;
}

void ULightingUtilitiesEditorSubsystem::ApplyMeshMaterialsForActiveLevels()
{
    if (!bIsPreviewActive)
    {
        return;
    }

    UWorld* World = GetSafeEditorWorld();
    if (!World)
    {
        return;
    }

    TArray<FString> ActiveLevels = GetAllActiveMapAndSublevelNames(World);
    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Applying materials for %d active levels (Mode: %d)..."),
        ActiveLevels.Num(), (int32)CurrentLightingMode);

    // Map actors by both FullPath:ActorName and ShortMapName:ActorName (case-insensitive)
    TMap<FString, AActor*> ActorsByMapAndName;
    for (TActorIterator<AActor> It(World); It; ++It)
    {
        if (AActor* Actor = *It)
        {
            if (ULevel* Level = Actor->GetLevel())
            {
                if (UPackage* LevelPackage = Level->GetOutermost())
                {
                    FString PackagePath = LevelPackage->GetName();
                    FString MapShortName = FPackageName::GetShortName(PackagePath);
                    FString ActorName = Actor->GetName();

                    FString FullKey = (PackagePath + TEXT(":") + ActorName).ToLower();
                    ActorsByMapAndName.Add(FullKey, Actor);

                    FString ShortKey = (MapShortName + TEXT(":") + ActorName).ToLower();
                    ActorsByMapAndName.Add(ShortKey, Actor);
                }
            }
        }
    }

    int32 OverriddenCount = 0;

    for (const TSharedPtr<FJsonValue>& EntryVal : CachedJsonEntries)
    {
        if (EntryVal->Type != EJson::Object)
        {
            continue;
        }

        TSharedPtr<FJsonObject> EntryObj = EntryVal->AsObject();
        FString Type = EntryObj->GetStringField(TEXT("Type"));
        if (!Type.Contains(TEXT("LightingMaterialManager")))
        {
            continue;
        }

        if (!EntryObj->HasField(TEXT("Properties")))
        {
            continue;
        }

        TSharedPtr<FJsonObject> PropertiesObj = EntryObj->GetObjectField(TEXT("Properties"));
        const TArray<TSharedPtr<FJsonValue>>* MeshMaterialsArray = nullptr;
        if (!PropertiesObj->TryGetArrayField(TEXT("MeshMaterials"), MeshMaterialsArray) || !MeshMaterialsArray)
        {
            continue;
        }

        for (const TSharedPtr<FJsonValue>& MeshMatVal : *MeshMaterialsArray)
        {
            if (MeshMatVal->Type != EJson::Object)
            {
                continue;
            }

            TSharedPtr<FJsonObject> MeshMatObj = MeshMatVal->AsObject();

            FString MaterialFieldKey;
            switch (CurrentLightingMode)
            {
            case ELightingUtilityMode::LightsOn:
                MaterialFieldKey = TEXT("LightsOnMaterials");
                break;
            case ELightingUtilityMode::LightsOff:
                MaterialFieldKey = TEXT("LightsOffMaterials");
                break;
            case ELightingUtilityMode::Dawn:
                MaterialFieldKey = TEXT("DawnMaterials");
                break;
            case ELightingUtilityMode::SpecialEvent:
                MaterialFieldKey = TEXT("SpecialEventMaterials");
                break;
            default:
                MaterialFieldKey = TEXT("LightsOnMaterials");
                break;
            }

            const TArray<TSharedPtr<FJsonValue>>* TargetMaterialsArray = nullptr;
            if (!MeshMatObj->TryGetArrayField(MaterialFieldKey, TargetMaterialsArray) || !TargetMaterialsArray || TargetMaterialsArray->Num() == 0)
            {
                MeshMatObj->TryGetArrayField(TEXT("LightsOnMaterials"), TargetMaterialsArray);
            }

            if (!TargetMaterialsArray || TargetMaterialsArray->Num() == 0)
            {
                continue;
            }

            TArray<UMaterialInterface*> TargetMaterials;
            for (const TSharedPtr<FJsonValue>& MatRefVal : *TargetMaterialsArray)
            {
                if (MatRefVal->Type == EJson::Object)
                {
                    FString ObjectPath;
                    MatRefVal->AsObject()->TryGetStringField(TEXT("ObjectPath"), ObjectPath);
                    if (UMaterialInterface* Mat = ResolveMaterialFromObjectPath(ObjectPath))
                    {
                        TargetMaterials.Add(Mat);
                    }
                }
            }

            if (TargetMaterials.Num() == 0)
            {
                continue;
            }

            const TArray<TSharedPtr<FJsonValue>>* StaticMeshActorArray = nullptr;
            if (!MeshMatObj->TryGetArrayField(TEXT("StaticMeshActor"), StaticMeshActorArray) || !StaticMeshActorArray)
            {
                continue;
            }

            for (const TSharedPtr<FJsonValue>& ActorRefVal : *StaticMeshActorArray)
            {
                if (ActorRefVal->Type != EJson::Object)
                {
                    continue;
                }

                TSharedPtr<FJsonObject> ActorRefObj = ActorRefVal->AsObject();
                FString AssetPathName, SubPathString;
                ActorRefObj->TryGetStringField(TEXT("AssetPathName"), AssetPathName);
                ActorRefObj->TryGetStringField(TEXT("SubPathString"), SubPathString);

                FString TargetPackagePath = AssetPathName;
                int32 DotIndex = INDEX_NONE;
                if (TargetPackagePath.FindChar('.', DotIndex))
                {
                    TargetPackagePath = TargetPackagePath.Left(DotIndex);
                }
                FString TargetMapShortName = FPackageName::GetShortName(TargetPackagePath);

                FString ActorName = SubPathString;
                if (ActorName.FindLastChar('.', DotIndex))
                {
                    ActorName = ActorName.Mid(DotIndex + 1);
                }

                FString QueryFullKey = (TargetPackagePath + TEXT(":") + ActorName).ToLower();
                FString QueryShortKey = (TargetMapShortName + TEXT(":") + ActorName).ToLower();

                AActor* FoundActor = nullptr;
                if (AActor** Ptr = ActorsByMapAndName.Find(QueryFullKey))
                {
                    FoundActor = *Ptr;
                }
                else if (AActor** PtrShort = ActorsByMapAndName.Find(QueryShortKey))
                {
                    FoundActor = *PtrShort;
                }

                if (!FoundActor)
                {
                    continue;
                }

                UStaticMeshComponent* MeshComp = FoundActor->FindComponentByClass<UStaticMeshComponent>();
                if (!MeshComp)
                {
                    continue;
                }

                if (!OriginalComponentMaterials.Contains(MeshComp))
                {
                    FCachedMaterialState OriginalState;
                    for (int32 Slot = 0; Slot < MeshComp->GetNumMaterials(); ++Slot)
                    {
                        OriginalState.OriginalMaterials.Add(MeshComp->GetMaterial(Slot));
                    }
                    OriginalComponentMaterials.Add(MeshComp, OriginalState);
                }

                for (int32 Slot = 0; Slot < TargetMaterials.Num(); ++Slot)
                {
                    if (TargetMaterials[Slot])
                    {
                        MeshComp->SetMaterial(Slot, TargetMaterials[Slot]);
                    }
                }

                OverriddenCount++;
            }
        }
    }

    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Successfully applied preview materials to %d mesh actors in matching maps!"), OverriddenCount);

    if (GEditor)
    {
        GEditor->RedrawLevelEditingViewports();
    }
}

void ULightingUtilitiesEditorSubsystem::RevertAllMeshMaterials()
{
    for (auto& Pair : OriginalComponentMaterials)
    {
        if (UStaticMeshComponent* MeshComp = Pair.Key.Get())
        {
            const TArray<UMaterialInterface*>& OrigMats = Pair.Value.OriginalMaterials;
            for (int32 Slot = 0; Slot < OrigMats.Num(); ++Slot)
            {
                MeshComp->SetMaterial(Slot, OrigMats[Slot]);
            }
        }
    }
    OriginalComponentMaterials.Empty();
}

void ULightingUtilitiesEditorSubsystem::RevertToOriginalMaterials()
{
    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Reverting materials and deactivating preview mode."));
    bIsPreviewActive = false;
    LastAppliedSignature.Empty();
    RevertAllMeshMaterials();

    if (GEditor)
    {
        GEditor->RedrawLevelEditingViewports();
    }
}

void ULightingUtilitiesEditorSubsystem::ClearPreview()
{
    bIsPreviewActive = false;
    LastAppliedSignature.Empty();
    RevertAllMeshMaterials();

    if (GEditor)
    {
        GEditor->RedrawLevelEditingViewports();
    }
}

void ULightingUtilitiesEditorSubsystem::OnPreSaveWorld(uint32 SaveFlags, UWorld* World)
{
    if (bIsPreviewActive)
    {
        UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] PreSaveWorld: Reverting %d actors before map save!"),
            OriginalComponentMaterials.Num());
        RevertAllMeshMaterials();
    }
}

void ULightingUtilitiesEditorSubsystem::OnPostSaveWorld(uint32 SaveFlags, UWorld* World, bool bSuccess)
{
    if (bIsPreviewActive)
    {
        UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] PostSaveWorld: Restoring preview materials."));
        ApplyMeshMaterialsForActiveLevels();
    }
}