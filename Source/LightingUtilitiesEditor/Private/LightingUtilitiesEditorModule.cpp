#include "LightingUtilitiesEditorModule.h"
#include "SLightingUtilitiesPreviewPanel.h"
#include "LightingUtilitiesEditorSubsystem.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "EditorStyleSet.h"
#include "Editor.h"

static const FName LightingUtilitiesTabName("LightingUtilitiesEditorTab");

#define LOCTEXT_NAMESPACE "FLightingUtilitiesEditorModule"

void FLightingUtilitiesEditorModule::StartupModule()
{
    // 1. Register the nomad tab spawner
    FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
        LightingUtilitiesTabName,
        FOnSpawnTab::CreateRaw(this, &FLightingUtilitiesEditorModule::OnSpawnPluginTab))
        .SetDisplayName(LOCTEXT("LightingUtilitiesTabTitle", "Lighting Utilities"))
        .SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "ClassIcon.PointLight"))
        .SetMenuType(ETabSpawnerMenuType::Hidden);

    // 2. Register toolbar extender
    ToolbarExtender = MakeShareable(new FExtender);
    ToolbarExtender->AddToolBarExtension(
        "Settings",
        EExtensionHook::After,
        nullptr,
        FToolBarExtensionDelegate::CreateRaw(this, &FLightingUtilitiesEditorModule::AddToolbarExtension)
    );

    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
    LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
}

void FLightingUtilitiesEditorModule::ShutdownModule()
{
    FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(LightingUtilitiesTabName);

    if (FModuleManager::Get().IsModuleLoaded("LevelEditor"))
    {
        FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>("LevelEditor");
        LevelEditorModule.GetToolBarExtensibilityManager()->RemoveExtender(ToolbarExtender);
    }
}

TSharedRef<SDockTab> FLightingUtilitiesEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
    return SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(SLightingUtilitiesPreviewPanel)
        ];
}

void FLightingUtilitiesEditorModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
    Builder.AddSeparator();

    // Toolbar combo button with dropdown menu
    Builder.AddComboButton(
        FUIAction(),
        FOnGetContent::CreateRaw(this, &FLightingUtilitiesEditorModule::GenerateLightingUtilitiesMenu),
        LOCTEXT("LightingUtilitiesBtn", "Lighting Utilities"),
        LOCTEXT("LightingUtilitiesBtnTooltip", "Choose active Lighting Utilities map or open controls"),
        FSlateIcon(FEditorStyle::GetStyleSetName(), "ClassIcon.PointLight")
    );
}

TSharedRef<SWidget> FLightingUtilitiesEditorModule::GenerateLightingUtilitiesMenu()
{
    FMenuBuilder MenuBuilder(true, nullptr);

    ULightingUtilitiesEditorSubsystem* Subsystem = GEditor ? GEditor->GetEditorSubsystem<ULightingUtilitiesEditorSubsystem>() : nullptr;
    if (Subsystem)
    {
        MenuBuilder.BeginSection("LightingMaps", LOCTEXT("SelectMapSection", "Select Lighting Utilities Map"));

        TArray<FString> AvailableMaps = Subsystem->GetAvailableUtilityMaps();
        FString CurrentSelected = Subsystem->GetSelectedUtilityMap();

        for (const FString& MapPath : AvailableMaps)
        {
            FText Label = FText::FromString(FPackageName::GetShortName(MapPath));
            FText Tooltip = FText::FromString(MapPath);

            MenuBuilder.AddMenuEntry(
                Label,
                Tooltip,
                FSlateIcon(FEditorStyle::GetStyleSetName(), "ClassIcon.World"),
                FUIAction(
                    FExecuteAction::CreateLambda([Subsystem, MapPath]() {
                Subsystem->SetSelectedUtilityMap(MapPath);
            }),
                    FCanExecuteAction(),
                    FIsActionChecked::CreateLambda([Subsystem, MapPath]() {
                return Subsystem && Subsystem->GetSelectedUtilityMap() == MapPath;
            })
                ),
                NAME_None,
                EUserInterfaceActionType::RadioButton
            );
        }
        MenuBuilder.EndSection();

        MenuBuilder.BeginSection("QuickControls", LOCTEXT("QuickControlsSection", "Quick Controls"));
        MenuBuilder.AddMenuEntry(
            LOCTEXT("ApplyBtn", "Apply Preview"),
            LOCTEXT("ApplyTooltip", "Apply lighting materials to open sublevels"),
            FSlateIcon(FEditorStyle::GetStyleSetName(), "Icons.Play"),
            FUIAction(FExecuteAction::CreateUObject(Subsystem, &ULightingUtilitiesEditorSubsystem::ApplyLighting))
        );
        MenuBuilder.AddMenuEntry(
            LOCTEXT("RevertBtn", "Revert Materials"),
            LOCTEXT("RevertTooltip", "Revert all materials to original state"),
            FSlateIcon(FEditorStyle::GetStyleSetName(), "Icons.Undo"),
            FUIAction(FExecuteAction::CreateUObject(Subsystem, &ULightingUtilitiesEditorSubsystem::RevertToOriginalMaterials))
        );
        MenuBuilder.EndSection();
    }

    MenuBuilder.BeginSection("WindowSection", LOCTEXT("WindowSectionLabel", "Window"));
    MenuBuilder.AddMenuEntry(
        LOCTEXT("OpenPanelBtn", "Open Lighting Utilities Window..."),
        LOCTEXT("OpenPanelTooltip", "Opens the full dockable preview window"),
        FSlateIcon(FEditorStyle::GetStyleSetName(), "ClassIcon.PointLight"),
        FUIAction(FExecuteAction::CreateRaw(this, &FLightingUtilitiesEditorModule::PluginButtonClicked))
    );
    MenuBuilder.EndSection();

    return MenuBuilder.MakeWidget();
}

void FLightingUtilitiesEditorModule::PluginButtonClicked()
{
    FGlobalTabmanager::Get()->TryInvokeTab(LightingUtilitiesTabName);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FLightingUtilitiesEditorModule, LightingUtilitiesEditor)