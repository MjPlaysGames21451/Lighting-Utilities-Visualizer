// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ELightingUtilityMode : uint8;
#ifdef LIGHTINGUTILITIESEDITOR_LightingUtilitiesEditorSubsystem_generated_h
#error "LightingUtilitiesEditorSubsystem.generated.h already included, missing '#pragma once' in LightingUtilitiesEditorSubsystem.h"
#endif
#define LIGHTINGUTILITIESEDITOR_LightingUtilitiesEditorSubsystem_generated_h

#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCachedMaterialState_Statics; \
	LIGHTINGUTILITIESEDITOR_API static class UScriptStruct* StaticStruct();


template<> LIGHTINGUTILITIESEDITOR_API UScriptStruct* StaticStruct<struct FCachedMaterialState>();

#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_SPARSE_DATA
#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClearPreview); \
	DECLARE_FUNCTION(execRefreshLighting); \
	DECLARE_FUNCTION(execHasPendingOverrides); \
	DECLARE_FUNCTION(execGetLoadedEntryCount); \
	DECLARE_FUNCTION(execReloadData); \
	DECLARE_FUNCTION(execRevertToOriginalMaterials); \
	DECLARE_FUNCTION(execSetCurrentLightingMode); \
	DECLARE_FUNCTION(execApplyLighting); \
	DECLARE_FUNCTION(execSetSelectedUtilityMap); \
	DECLARE_FUNCTION(execGetSelectedUtilityMap); \
	DECLARE_FUNCTION(execGetAvailableUtilityMaps);


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClearPreview); \
	DECLARE_FUNCTION(execRefreshLighting); \
	DECLARE_FUNCTION(execHasPendingOverrides); \
	DECLARE_FUNCTION(execGetLoadedEntryCount); \
	DECLARE_FUNCTION(execReloadData); \
	DECLARE_FUNCTION(execRevertToOriginalMaterials); \
	DECLARE_FUNCTION(execSetCurrentLightingMode); \
	DECLARE_FUNCTION(execApplyLighting); \
	DECLARE_FUNCTION(execSetSelectedUtilityMap); \
	DECLARE_FUNCTION(execGetSelectedUtilityMap); \
	DECLARE_FUNCTION(execGetAvailableUtilityMaps);


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULightingUtilitiesEditorSubsystem(); \
	friend struct Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics; \
public: \
	DECLARE_CLASS(ULightingUtilitiesEditorSubsystem, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LightingUtilitiesEditor"), NO_API) \
	DECLARE_SERIALIZER(ULightingUtilitiesEditorSubsystem)


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_INCLASS \
private: \
	static void StaticRegisterNativesULightingUtilitiesEditorSubsystem(); \
	friend struct Z_Construct_UClass_ULightingUtilitiesEditorSubsystem_Statics; \
public: \
	DECLARE_CLASS(ULightingUtilitiesEditorSubsystem, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LightingUtilitiesEditor"), NO_API) \
	DECLARE_SERIALIZER(ULightingUtilitiesEditorSubsystem)


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULightingUtilitiesEditorSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULightingUtilitiesEditorSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULightingUtilitiesEditorSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULightingUtilitiesEditorSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULightingUtilitiesEditorSubsystem(ULightingUtilitiesEditorSubsystem&&); \
	NO_API ULightingUtilitiesEditorSubsystem(const ULightingUtilitiesEditorSubsystem&); \
public:


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULightingUtilitiesEditorSubsystem() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULightingUtilitiesEditorSubsystem(ULightingUtilitiesEditorSubsystem&&); \
	NO_API ULightingUtilitiesEditorSubsystem(const ULightingUtilitiesEditorSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULightingUtilitiesEditorSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULightingUtilitiesEditorSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULightingUtilitiesEditorSubsystem)


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__OriginalComponentMaterials() { return STRUCT_OFFSET(ULightingUtilitiesEditorSubsystem, OriginalComponentMaterials); } \
	FORCEINLINE static uint32 __PPO__LoadedMaterialCache() { return STRUCT_OFFSET(ULightingUtilitiesEditorSubsystem, LoadedMaterialCache); }


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_21_PROLOG
#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_PRIVATE_PROPERTY_OFFSET \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_SPARSE_DATA \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_RPC_WRAPPERS \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_INCLASS \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_PRIVATE_PROPERTY_OFFSET \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_SPARSE_DATA \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_INCLASS_NO_PURE_DECLS \
	SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIGHTINGUTILITIESEDITOR_API UClass* StaticClass<class ULightingUtilitiesEditorSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesEditorSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
