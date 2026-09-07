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
#include "PackageTools.h"
#include "JsonObjectConverter.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

DEFINE_LOG_CATEGORY_STATIC(LogLightingUtils, Log, All);

void ULightingUtilitiesEditorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    UE_LOG(LogLightingUtils, Display, TEXT("[LightingUtilities] Subsystem Initialized. (Package load deferred until Editor World is ready)"));

    FEditorDelegates::OnMapOpened.AddUObject(this, &ULightingUtilitiesEditorSubsystem::OnMapOpened);
    FEditorDelegates::PreSaveWorld.AddUObject(this, &ULightingUtilitiesEditorSubsystem::OnPreSaveWorld);
    FEditorDelegates::PostSaveWorld.AddUObject(this, &ULightingUtilitiesEditorSubsystem::OnPostSaveWorld);

    // DO NOT load .umap packages here! GEngine is not fully initialized during subsystem registration.
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

    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Active Utility Map switched to: '%s'"), *InMapPackage);
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

    // 2. Sublevels in memory
    for (ULevel* Level : World->GetLevels())
    {
        if (Level && Level->GetOutermost())
        {
            FString LevelPackage = Level->GetOutermost()->GetName();
            LevelNames.AddUnique(LevelPackage);
            LevelNames.AddUnique(FPackageName::GetShortName(LevelPackage));
        }
    }

    // 3. Streaming levels
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

    // Load data now that engine and world are fully initialized
    if (CachedEntries.Num() == 0)
    {
        ReloadData();
    }

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

    UWorld* World = GetSafeEditorWorld();
    if (!World)
    {
        return; // Wait until Editor World is up
    }

    // First safe opportunity to load the map package
    if (CachedEntries.Num() == 0)
    {
        ReloadData();
    }

    const bool bFilesChanged = CheckForFileUpdates();
    if (bFilesChanged)
    {
        UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Target map asset updated on disk! Reloading live package..."));

        UPackage* ExistingPackage = FindPackage(nullptr, *TargetUtilityPackage);
        if (ExistingPackage)
        {
            TArray<UPackage*> PackagesToReload = { ExistingPackage };
            UPackageTools::ReloadPackages(PackagesToReload);
        }

        ReloadData();
    }

    if (!bIsPreviewActive)
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

    return bUpdated;
}

void ULightingUtilitiesEditorSubsystem::ReloadData()
{
    UWorld* World = GetSafeEditorWorld();
    if (!World)
    {
        return; // Guard against running before engine is fully initialized
    }

    CachedEntries.Empty();

    // 1. Try loading directly from the actual .umap asset package
    bool bLoadedFromUmap = LoadDataFromMapPackage();

    // 2. Fallback to JSON only if the .umap could not be read
    if (!bLoadedFromUmap || CachedEntries.Num() == 0)
    {
        UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Could not read actors directly from '%s', attempting JSON fallback..."), *TargetUtilityPackage);
        LoadDataFromFallbackJson();
    }

    if (bIsPreviewActive)
    {
        RefreshLighting(true);
    }
}

bool ULightingUtilitiesEditorSubsystem::LoadDataFromMapPackage()
{
    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Loading actual map asset: '%s'..."), *TargetUtilityPackage);

    UPackage* MapPackage = FindPackage(nullptr, *TargetUtilityPackage);
    if (!MapPackage)
    {
        MapPackage = LoadPackage(nullptr, *TargetUtilityPackage, LOAD_None);
    }

    if (!MapPackage)
    {
        UE_LOG(LogLightingUtils, Error, TEXT("[LightingUtilities] Failed to load package '%s'"), *TargetUtilityPackage);
        return false;
    }

    int32 FoundManagers = 0;

    // Direct extraction via UWorld::FindWorldInPackage
    UWorld* LoadedWorld = UWorld::FindWorldInPackage(MapPackage);
    if (LoadedWorld && LoadedWorld->PersistentLevel)
    {
        for (AActor* Actor : LoadedWorld->PersistentLevel->Actors)
        {
            if (!Actor)
            {
                continue;
            }

            UClass* ActorClass = Actor->GetClass();
            FProperty* MeshMaterialsProp = ActorClass->FindPropertyByName(TEXT("MeshMaterials"));
            if (!MeshMaterialsProp)
            {
                continue;
            }

            TSharedPtr<FJsonObject> ActorJson = MakeShareable(new FJsonObject);
            ActorJson->SetStringField(TEXT("Type"), TEXT("LightingMaterialManager"));
            ActorJson->SetStringField(TEXT("Name"), Actor->GetName());
            ActorJson->SetStringField(TEXT("Class"), ActorClass->GetName());

            TSharedPtr<FJsonObject> PropertiesJson = MakeShareable(new FJsonObject);
            if (FJsonObjectConverter::UStructToJsonObject(ActorClass, Actor, PropertiesJson.ToSharedRef(), 0, 0))
            {
                ActorJson->SetObjectField(TEXT("Properties"), PropertiesJson);
                CachedEntries.Add(MakeShareable(new FJsonValueObject(ActorJson)));
                FoundManagers++;

                UE_LOG(LogLightingUtils, Log, TEXT("   Found Manager Actor: '%s' (%s)"), *Actor->GetName(), *ActorClass->GetName());
            }
        }
    }

    // Secondary fallback: scan objects inside package if world was not resolved
    if (FoundManagers == 0)
    {
        TArray<UObject*> PackageObjects;
        GetObjectsWithOuter(MapPackage, PackageObjects, true);

        for (UObject* Obj : PackageObjects)
        {
            AActor* Actor = Cast<AActor>(Obj);
            if (!Actor)
            {
                continue;
            }

            UClass* ActorClass = Actor->GetClass();
            FProperty* MeshMaterialsProp = ActorClass->FindPropertyByName(TEXT("MeshMaterials"));
            if (!MeshMaterialsProp)
            {
                continue;
            }

            TSharedPtr<FJsonObject> ActorJson = MakeShareable(new FJsonObject);
            ActorJson->SetStringField(TEXT("Type"), TEXT("LightingMaterialManager"));
            ActorJson->SetStringField(TEXT("Name"), Actor->GetName());
            ActorJson->SetStringField(TEXT("Class"), ActorClass->GetName());

            TSharedPtr<FJsonObject> PropertiesJson = MakeShareable(new FJsonObject);
            if (FJsonObjectConverter::UStructToJsonObject(ActorClass, Actor, PropertiesJson.ToSharedRef(), 0, 0))
            {
                ActorJson->SetObjectField(TEXT("Properties"), PropertiesJson);
                CachedEntries.Add(MakeShareable(new FJsonValueObject(ActorJson)));
                FoundManagers++;
            }
        }
    }

    if (FoundManagers > 0)
    {
        UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] SUCCESS: Read %d LightingMaterialManager actors DIRECTLY from '%s' (.umap/.uexp)!"),
            FoundManagers, *TargetUtilityPackage);
        return true;
    }

    return false;
}

void ULightingUtilitiesEditorSubsystem::LoadDataFromFallbackJson()
{
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
            FJsonSerializer::Deserialize(Reader, CachedEntries);
            UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Fallback: Loaded %d entries from JSON file '%s'."),
                CachedEntries.Num(), *FoundJsonPath);
        }
    }
}

void ULightingUtilitiesEditorSubsystem::ApplyLighting()
{
    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] ApplyLighting triggered! Activating preview."));
    bIsPreviewActive = true;
    if (CachedEntries.Num() == 0)
    {
        ReloadData();
    }
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
    FString ActiveLevelsStr = FString::Join(ActiveLevels, TEXT(", "));
    UE_LOG(LogLightingUtils, Warning, TEXT("[LightingUtilities] Applying materials for %d active levels: [ %s ] (Mode: %d)..."),
        ActiveLevels.Num(), *ActiveLevelsStr, (int32)CurrentLightingMode);

    // Build map of actors in current world keyed by "mappackage:actorname" and "shortmapname:actorname"
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

    for (const TSharedPtr<FJsonValue>& EntryVal : CachedEntries)
    {
        if (EntryVal->Type != EJson::Object)
        {
            continue;
        }

        TSharedPtr<FJsonObject> EntryObj = EntryVal->AsObject();
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

            // Select material array based on lighting mode
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

            // Resolve target materials (supports both String and Object entries)
            TArray<UMaterialInterface*> TargetMaterials;
            for (const TSharedPtr<FJsonValue>& MatRefVal : *TargetMaterialsArray)
            {
                FString ObjectPath;
                if (MatRefVal->Type == EJson::String)
                {
                    ObjectPath = MatRefVal->AsString();
                }
                else if (MatRefVal->Type == EJson::Object)
                {
                    TSharedPtr<FJsonObject> MatObj = MatRefVal->AsObject();
                    if (!MatObj->TryGetStringField(TEXT("ObjectPath"), ObjectPath))
                    {
                        MatObj->TryGetStringField(TEXT("AssetPathName"), ObjectPath);
                    }
                }

                if (!ObjectPath.IsEmpty())
                {
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

            // Resolve static mesh actors (supports both String and Object entries)
            const TArray<TSharedPtr<FJsonValue>>* StaticMeshActorArray = nullptr;
            if (!MeshMatObj->TryGetArrayField(TEXT("StaticMeshActor"), StaticMeshActorArray) || !StaticMeshActorArray)
            {
                continue;
            }

            for (const TSharedPtr<FJsonValue>& ActorRefVal : *StaticMeshActorArray)
            {
                FString TargetPackagePath;
                FString ActorSubPath;

                if (ActorRefVal->Type == EJson::String)
                {
                    // Live map serialization formats FSoftObjectPath as a string
                    FSoftObjectPath SoftPath(ActorRefVal->AsString());
                    TargetPackagePath = SoftPath.GetAssetPathString();
                    ActorSubPath = SoftPath.GetSubPathString();

                    // Fallback parsing if SubPathString was not populated
                    if (ActorSubPath.IsEmpty())
                    {
                        FString FullStr = ActorRefVal->AsString();
                        int32 ColonIdx = INDEX_NONE;
                        if (FullStr.FindChar(':', ColonIdx))
                        {
                            TargetPackagePath = FullStr.Left(ColonIdx);
                            ActorSubPath = FullStr.Mid(ColonIdx + 1);
                        }
                    }
                }
                else if (ActorRefVal->Type == EJson::Object)
                {
                    TSharedPtr<FJsonObject> ActorRefObj = ActorRefVal->AsObject();
                    ActorRefObj->TryGetStringField(TEXT("AssetPathName"), TargetPackagePath);
                    ActorRefObj->TryGetStringField(TEXT("SubPathString"), ActorSubPath);
                }

                // Clean package name (strip dot asset names)
                int32 DotIndex = INDEX_NONE;
                if (TargetPackagePath.FindChar('.', DotIndex))
                {
                    TargetPackagePath = TargetPackagePath.Left(DotIndex);
                }
                FString TargetMapShortName = FPackageName::GetShortName(TargetPackagePath);

                // Clean actor name (e.g. "PersistentLevel.MOD_Techlight78_160" -> "MOD_Techlight78_160")
                FString ActorName = ActorSubPath;
                if (ActorName.FindLastChar('.', DotIndex))
                {
                    ActorName = ActorName.Mid(DotIndex + 1);
                }

                if (ActorName.IsEmpty())
                {
                    continue;
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

                // If not found in the currently loaded level/sublevels, skip
                if (!FoundActor)
                {
                    continue;
                }

                UStaticMeshComponent* MeshComp = FoundActor->FindComponentByClass<UStaticMeshComponent>();
                if (!MeshComp)
                {
                    continue;
                }

                // Cache original materials before overriding
                if (!OriginalComponentMaterials.Contains(MeshComp))
                {
                    FCachedMaterialState OriginalState;
                    for (int32 Slot = 0; Slot < MeshComp->GetNumMaterials(); ++Slot)
                    {
                        OriginalState.OriginalMaterials.Add(MeshComp->GetMaterial(Slot));
                    }
                    OriginalComponentMaterials.Add(MeshComp, OriginalState);
                }

                // Apply target materials
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