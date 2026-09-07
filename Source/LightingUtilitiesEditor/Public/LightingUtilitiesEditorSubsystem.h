#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "TickableEditorObject.h"
#include "LightingUtilitiesTypes.h"
#include "Materials/MaterialInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Dom/JsonObject.h"
#include "LightingUtilitiesEditorSubsystem.generated.h"

USTRUCT()
struct FCachedMaterialState
{
    GENERATED_BODY()

    UPROPERTY()
    TArray<UMaterialInterface*> OriginalMaterials;
};

UCLASS()
class LIGHTINGUTILITIESEDITOR_API ULightingUtilitiesEditorSubsystem : public UEditorSubsystem, public FTickableEditorObject
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    // FTickableEditorObject
    virtual void Tick(float DeltaTime) override;
    virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
    virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(ULightingUtilitiesEditorSubsystem, STATGROUP_Tickables); }

    // --- Map Selection API ---

    /** Searches /Game/ for all maps named *LightingUtilities* */
    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    TArray<FString> GetAvailableUtilityMaps();

    /** Returns currently selected utility map package */
    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    FString GetSelectedUtilityMap() const { return TargetUtilityPackage; }

    /** Sets the active utility map and reloads directly from that .umap */
    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    void SetSelectedUtilityMap(const FString& InMapPackage);

    // --- Panel & Control Interface ---

    /** Activates preview and applies materials */
    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    void ApplyLighting();

    void SetLightingMode();

    template<typename T>
    void SetLightingMode(T InMode)
    {
        CurrentLightingMode = static_cast<ELightingUtilityMode>(static_cast<uint8>(InMode));
        bIsPreviewActive = true;
        RefreshLighting(true);
    }

    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    void SetCurrentLightingMode(ELightingUtilityMode InMode);

    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    void RevertToOriginalMaterials();

    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    void ReloadData();

    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    int32 GetLoadedEntryCount() const { return CachedEntries.Num(); }

    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    bool HasPendingOverrides() const { return bIsPreviewActive && OriginalComponentMaterials.Num() > 0; }

    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    void RefreshLighting(bool bForce = false);

    UFUNCTION(BlueprintCallable, Category = "Lighting Utilities")
    void ClearPreview();

private:
    /** Default map path */
    FString TargetUtilityPackage = TEXT("/Game/Maps/World/MAP_LightingUtilities");

    bool bIsPreviewActive = false;

    ELightingUtilityMode CurrentLightingMode = static_cast<ELightingUtilityMode>(0);

    FDateTime LastUmapTimestamp = FDateTime::MinValue();
    FDateTime LastUexpTimestamp = FDateTime::MinValue();

    FString LastAppliedSignature;
    float TimeSinceLastCheck = 0.0f;
    const float CheckInterval = 0.5f;

    /** In-memory data parsed directly from the live .umap actors */
    TArray<TSharedPtr<FJsonValue>> CachedEntries;

    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<UStaticMeshComponent>, FCachedMaterialState> OriginalComponentMaterials;

    UPROPERTY(Transient)
    TMap<FString, UMaterialInterface*> LoadedMaterialCache;

    UWorld* GetSafeEditorWorld() const;
    TArray<FString> GetAllActiveMapAndSublevelNames(UWorld* World) const;

    void OnMapOpened(const FString& Filename, bool bAsTemplate);
    void OnPreSaveWorld(uint32 SaveFlags, UWorld* World);
    void OnPostSaveWorld(uint32 SaveFlags, UWorld* World, bool bSuccess);

    bool CheckForFileUpdates();
    bool LoadDataFromMapPackage();
    void LoadDataFromFallbackJson();

    void ApplyMeshMaterialsForActiveLevels();
    void RevertAllMeshMaterials();

    UMaterialInterface* ResolveMaterialFromObjectPath(const FString& ObjectPath);
};