// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LightingUtilitiesEditor/Public/LightingUtilitiesEditorSubsystem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLightingUtilitiesEditorSubsystem() {}
// Cross Module References
	LIGHTINGUTILITIESEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FCachedMaterialState();
	UPackage* Z_Construct_UPackage__Script_LightingUtilitiesEditor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	LIGHTINGUTILITIESEDITOR_API UClass* Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_NoRegister();
	LIGHTINGUTILITIESEDITOR_API UClass* Z_Construct_UClass_ULightingUtilitiesEditorSubsystem();
	EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
	LIGHTINGUTILITIESEDITOR_API UEnum* Z_Construct_UEnum_LightingUtilitiesEditor_ELightingUtilityMode();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
class UScriptStruct* FCachedMaterialState::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern LIGHTINGUTILITIESEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FCachedMaterialState_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCachedMaterialState, Z_Construct_UPackage__Script_LightingUtilitiesEditor(), TEXT("CachedMaterialState"), sizeof(FCachedMaterialState), Get_Z_Construct_UScriptStruct_FCachedMaterialState_Hash());
	}
	return Singleton;
}
template<> LIGHTINGUTILITIESEDITOR_API UScriptStruct* StaticStruct<FCachedMaterialState>()
{
	return FCachedMaterialState::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCachedMaterialState(FCachedMaterialState::StaticStruct, TEXT("/Script/LightingUtilitiesEditor"), TEXT("CachedMaterialState"), false, nullptr, nullptr);
static struct FScriptStruct_LightingUtilitiesEditor_StaticRegisterNativesFCachedMaterialState
{
	FScriptStruct_LightingUtilitiesEditor_StaticRegisterNativesFCachedMaterialState()
	{
		UScriptStruct::DeferCppStructOps<FCachedMaterialState>(FName(TEXT("CachedMaterialState")));
	}
} ScriptStruct_LightingUtilitiesEditor_StaticRegisterNativesFCachedMaterialState;
	struct Z_Construct_UScriptStruct_FCachedMaterialState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OriginalMaterials_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OriginalMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OriginalMaterials;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCachedMaterialState_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCachedMaterialState>();
	}
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewProp_OriginalMaterials_Inner = { "OriginalMaterials", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewProp_OriginalMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewProp_OriginalMaterials = { "OriginalMaterials", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCachedMaterialState, OriginalMaterials), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewProp_OriginalMaterials_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewProp_OriginalMaterials_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCachedMaterialState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewProp_OriginalMaterials_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCachedMaterialState_Statics::NewProp_OriginalMaterials,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCachedMaterialState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_LightingUtilitiesEditor,
		nullptr,
		&NewStructOps,
		"CachedMaterialState",
		sizeof(FCachedMaterialState),
		alignof(FCachedMaterialState),
		Z_Construct_UScriptStruct_FCachedMaterialState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCachedMaterialState_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCachedMaterialState_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCachedMaterialState_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCachedMaterialState()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCachedMaterialState_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_LightingUtilitiesEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CachedMaterialState"), sizeof(FCachedMaterialState), Get_Z_Construct_UScriptStruct_FCachedMaterialState_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCachedMaterialState_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCachedMaterialState_Hash() { return 3864811825U; }
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execClearPreview)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearPreview();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execRefreshLighting)
	{
		P_GET_UBOOL(Z_Param_bForce);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RefreshLighting(Z_Param_bForce);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execHasPendingOverrides)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasPendingOverrides();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execGetLoadedEntryCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetLoadedEntryCount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execReloadData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReloadData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execRevertToOriginalMaterials)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RevertToOriginalMaterials();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execSetCurrentLightingMode)
	{
		P_GET_ENUM(ELightingUtilityMode,Z_Param_InMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentLightingMode(ELightingUtilityMode(Z_Param_InMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execApplyLighting)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ApplyLighting();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execSetSelectedUtilityMap)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InMapPackage);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSelectedUtilityMap(Z_Param_InMapPackage);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execGetSelectedUtilityMap)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSelectedUtilityMap();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULightingUtilitiesEditorSubsystem::execGetAvailableUtilityMaps)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetAvailableUtilityMaps();
		P_NATIVE_END;
	}
	void ULightingUtilitiesEditorSubsystem::StaticRegisterNativesULightingUtilitiesEditorSubsystem()
	{
		UClass* Class = ULightingUtilitiesEditorSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyLighting", &ULightingUtilitiesEditorSubsystem::execApplyLighting },
			{ "ClearPreview", &ULightingUtilitiesEditorSubsystem::execClearPreview },
			{ "GetAvailableUtilityMaps", &ULightingUtilitiesEditorSubsystem::execGetAvailableUtilityMaps },
			{ "GetLoadedEntryCount", &ULightingUtilitiesEditorSubsystem::execGetLoadedEntryCount },
			{ "GetSelectedUtilityMap", &ULightingUtilitiesEditorSubsystem::execGetSelectedUtilityMap },
			{ "HasPendingOverrides", &ULightingUtilitiesEditorSubsystem::execHasPendingOverrides },
			{ "RefreshLighting", &ULightingUtilitiesEditorSubsystem::execRefreshLighting },
			{ "ReloadData", &ULightingUtilitiesEditorSubsystem::execReloadData },
			{ "RevertToOriginalMaterials", &ULightingUtilitiesEditorSubsystem::execRevertToOriginalMaterials },
			{ "SetCurrentLightingMode", &ULightingUtilitiesEditorSubsystem::execSetCurrentLightingMode },
			{ "SetSelectedUtilityMap", &ULightingUtilitiesEditorSubsystem::execSetSelectedUtilityMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "Comment", "/** Activates preview and applies materials */" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
		{ "ToolTip", "Activates preview and applies materials" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "ApplyLighting", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "ClearPreview", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics
	{
		struct LightingUtilitiesEditorSubsystem_eventGetAvailableUtilityMaps_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LightingUtilitiesEditorSubsystem_eventGetAvailableUtilityMaps_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "Comment", "/** Searches /Game/ for all maps named *LightingUtilities* */" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
		{ "ToolTip", "Searches /Game/ for all maps named *LightingUtilities*" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "GetAvailableUtilityMaps", nullptr, nullptr, sizeof(LightingUtilitiesEditorSubsystem_eventGetAvailableUtilityMaps_Parms), Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics
	{
		struct LightingUtilitiesEditorSubsystem_eventGetLoadedEntryCount_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LightingUtilitiesEditorSubsystem_eventGetLoadedEntryCount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "GetLoadedEntryCount", nullptr, nullptr, sizeof(LightingUtilitiesEditorSubsystem_eventGetLoadedEntryCount_Parms), Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics
	{
		struct LightingUtilitiesEditorSubsystem_eventGetSelectedUtilityMap_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LightingUtilitiesEditorSubsystem_eventGetSelectedUtilityMap_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "Comment", "/** Returns the currently selected utility map package */" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
		{ "ToolTip", "Returns the currently selected utility map package" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "GetSelectedUtilityMap", nullptr, nullptr, sizeof(LightingUtilitiesEditorSubsystem_eventGetSelectedUtilityMap_Parms), Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics
	{
		struct LightingUtilitiesEditorSubsystem_eventHasPendingOverrides_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((LightingUtilitiesEditorSubsystem_eventHasPendingOverrides_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(LightingUtilitiesEditorSubsystem_eventHasPendingOverrides_Parms), &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "HasPendingOverrides", nullptr, nullptr, sizeof(LightingUtilitiesEditorSubsystem_eventHasPendingOverrides_Parms), Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics
	{
		struct LightingUtilitiesEditorSubsystem_eventRefreshLighting_Parms
		{
			bool bForce;
		};
		static void NewProp_bForce_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bForce;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::NewProp_bForce_SetBit(void* Obj)
	{
		((LightingUtilitiesEditorSubsystem_eventRefreshLighting_Parms*)Obj)->bForce = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::NewProp_bForce = { "bForce", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(LightingUtilitiesEditorSubsystem_eventRefreshLighting_Parms), &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::NewProp_bForce_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::NewProp_bForce,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "CPP_Default_bForce", "false" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "RefreshLighting", nullptr, nullptr, sizeof(LightingUtilitiesEditorSubsystem_eventRefreshLighting_Parms), Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "ReloadData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "RevertToOriginalMaterials", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics
	{
		struct LightingUtilitiesEditorSubsystem_eventSetCurrentLightingMode_Parms
		{
			ELightingUtilityMode InMode;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InMode_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_InMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::NewProp_InMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::NewProp_InMode = { "InMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LightingUtilitiesEditorSubsystem_eventSetCurrentLightingMode_Parms, InMode), Z_Construct_UEnum_LightingUtilitiesEditor_ELightingUtilityMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::NewProp_InMode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::NewProp_InMode,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "SetCurrentLightingMode", nullptr, nullptr, sizeof(LightingUtilitiesEditorSubsystem_eventSetCurrentLightingMode_Parms), Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics
	{
		struct LightingUtilitiesEditorSubsystem_eventSetSelectedUtilityMap_Parms
		{
			FString InMapPackage;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InMapPackage_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InMapPackage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::NewProp_InMapPackage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::NewProp_InMapPackage = { "InMapPackage", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LightingUtilitiesEditorSubsystem_eventSetSelectedUtilityMap_Parms, InMapPackage), METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::NewProp_InMapPackage_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::NewProp_InMapPackage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::NewProp_InMapPackage,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lighting Utilities" },
		{ "Comment", "/** Sets the active utility map and reloads data */" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
		{ "ToolTip", "Sets the active utility map and reloads data" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, nullptr, "SetSelectedUtilityMap", nullptr, nullptr, sizeof(LightingUtilitiesEditorSubsystem_eventSetSelectedUtilityMap_Parms), Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_NoRegister()
	{
		return ULightingUtilitiesEditorSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OriginalComponentMaterials_ValueProp;
		static const UE4CodeGen_Private::FWeakObjectPropertyParams NewProp_OriginalComponentMaterials_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OriginalComponentMaterials_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_OriginalComponentMaterials;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LoadedMaterialCache_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_LoadedMaterialCache_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LoadedMaterialCache_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_LoadedMaterialCache;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_LightingUtilitiesEditor,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ApplyLighting, "ApplyLighting" }, // 2505055458
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ClearPreview, "ClearPreview" }, // 2478619211
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetAvailableUtilityMaps, "GetAvailableUtilityMaps" }, // 3636440683
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetLoadedEntryCount, "GetLoadedEntryCount" }, // 1008962807
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_GetSelectedUtilityMap, "GetSelectedUtilityMap" }, // 17092273
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_HasPendingOverrides, "HasPendingOverrides" }, // 2822546906
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RefreshLighting, "RefreshLighting" }, // 3053040086
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_ReloadData, "ReloadData" }, // 194232948
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_RevertToOriginalMaterials, "RevertToOriginalMaterials" }, // 4083288200
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetCurrentLightingMode, "SetCurrentLightingMode" }, // 2697043878
		{ &Z_Construct_UFunction_ULightingUtilitiesEditorSubsystem_SetSelectedUtilityMap, "SetSelectedUtilityMap" }, // 1256473768
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LightingUtilitiesEditorSubsystem.h" },
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials_ValueProp = { "OriginalComponentMaterials", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FCachedMaterialState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials_Key_KeyProp = { "OriginalComponentMaterials_Key", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials = { "OriginalComponentMaterials", nullptr, (EPropertyFlags)0x0040000000002000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULightingUtilitiesEditorSubsystem, OriginalComponentMaterials), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache_ValueProp = { "LoadedMaterialCache", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache_Key_KeyProp = { "LoadedMaterialCache_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache_MetaData[] = {
		{ "ModuleRelativePath", "Public/LightingUtilitiesEditorSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache = { "LoadedMaterialCache", nullptr, (EPropertyFlags)0x0040000000002000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULightingUtilitiesEditorSubsystem, LoadedMaterialCache), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_OriginalComponentMaterials,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::NewProp_LoadedMaterialCache,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULightingUtilitiesEditorSubsystem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::ClassParams = {
		&ULightingUtilitiesEditorSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULightingUtilitiesEditorSubsystem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULightingUtilitiesEditorSubsystem, 1102270632);
	template<> LIGHTINGUTILITIESEDITOR_API UClass* StaticClass<ULightingUtilitiesEditorSubsystem>()
	{
		return ULightingUtilitiesEditorSubsystem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULightingUtilitiesEditorSubsystem(Z_Construct_UClass_ULightingUtilitiesEditorSubsystem, &ULightingUtilitiesEditorSubsystem::StaticClass, TEXT("/Script/LightingUtilitiesEditor"), TEXT("ULightingUtilitiesEditorSubsystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULightingUtilitiesEditorSubsystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
