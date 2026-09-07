#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

class FLightingUtilitiesEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    /** Spawns the dockable preview panel tab */
    TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

    /** Called when the open window button is clicked */
    void PluginButtonClicked();

private:
    void AddToolbarExtension(FToolBarBuilder& Builder);
    TSharedRef<SWidget> GenerateLightingUtilitiesMenu();

    TSharedPtr<class FExtender> ToolbarExtender;
};