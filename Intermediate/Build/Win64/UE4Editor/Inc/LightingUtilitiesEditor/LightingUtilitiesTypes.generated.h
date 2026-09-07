// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIGHTINGUTILITIESEDITOR_LightingUtilitiesTypes_generated_h
#error "LightingUtilitiesTypes.generated.h already included, missing '#pragma once' in LightingUtilitiesTypes.h"
#endif
#define LIGHTINGUTILITIESEDITOR_LightingUtilitiesTypes_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SBRUIN_Blank_4_27_Plugins_LightingUtilitiesEditor_Source_LightingUtilitiesEditor_Public_LightingUtilitiesTypes_h


#define FOREACH_ENUM_ELIGHTINGUTILITYMODE(op) \
	op(ELightingUtilityMode::LightsOn) \
	op(ELightingUtilityMode::LightsOff) \
	op(ELightingUtilityMode::Dawn) \
	op(ELightingUtilityMode::SpecialEvent) 

enum class ELightingUtilityMode : uint8;
template<> LIGHTINGUTILITIESEDITOR_API UEnum* StaticEnum<ELightingUtilityMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
