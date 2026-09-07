using UnrealBuildTool;

public class LightingUtilitiesEditor : ModuleRules
{
    public LightingUtilitiesEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "EditorSubsystem"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore",
                "EditorStyle",
                "WorkspaceMenuStructure",
                "LevelEditor",
                "UnrealEd",
                "Json",
                "JsonUtilities",
                "DirectoryWatcher"
            }
        );
    }
}