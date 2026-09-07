#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "LightingUtilitiesTypes.h"

class SLightingUtilitiesPreviewPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLightingUtilitiesPreviewPanel) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	TArray<TSharedPtr<FString>> ModeOptions;
	TSharedPtr<FString> SelectedMode;

	TSharedRef<SWidget> OnGenerateModeWidget(TSharedPtr<FString> InOption) const;
	void OnModeSelectionChanged(TSharedPtr<FString> NewSelection, ESelectInfo::Type SelectInfo);
	FText GetSelectedModeText() const;

	FReply OnApplyClicked();
	FReply OnRevertClicked();
	FReply OnReloadClicked();

	FText GetStatusText() const;

	static ELightingUtilityMode ModeFromString(const FString& InString);
};
