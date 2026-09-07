#pragma once

#include "CoreMinimal.h"
#include "LightingUtilitiesTypes.generated.h"

/**
 * Matches the four material lists a LightingMaterialManager mesh entry can define
 * in the UAssetAPI/FModel JSON export ("LightsOnMaterials", "LightsOffMaterials",
 * "DawnMaterials", "SpecialEventMaterials").
 */
UENUM(BlueprintType)
enum class ELightingUtilityMode : uint8
{
	LightsOn UMETA(DisplayName = "Lights On"),
	LightsOff UMETA(DisplayName = "Lights Off"),
	Dawn UMETA(DisplayName = "Dawn"),
	SpecialEvent UMETA(DisplayName = "Special Event")
};

// --- Plain (non-reflected) structs used only while parsing the JSON export. ---
// These never need to be UPROPERTY/BlueprintType since nothing outside the
// subsystem's .cpp ever touches them directly.

struct FLUActorRef
{
	FString AssetPathName; // e.g. /Game/Maps/StageArea/MAP_Atrium_Food_Court.MAP_Atrium_Food_Court
	FString SubPathString; // e.g. PersistentLevel.MOD_Techlight78_160
};

struct FLUMaterialRef
{
	FString ObjectName; // e.g. MaterialInstanceConstant'MAT_Techlight'
	FString ObjectPath; // e.g. /Game/ShadingAssets/Materials/MAT_Techlight
};

struct FLUMeshMaterialEntry
{
	FString ListName;
	TArray<FLUActorRef> StaticMeshActors;
	TArray<FLUMaterialRef> LightsOnMaterials;
	TArray<FLUMaterialRef> LightsOffMaterials;
	TArray<FLUMaterialRef> DawnMaterials;
	TArray<FLUMaterialRef> SpecialEventMaterials;
};
