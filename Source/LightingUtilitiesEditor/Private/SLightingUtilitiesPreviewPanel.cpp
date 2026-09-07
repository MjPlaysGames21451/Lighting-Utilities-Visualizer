#include "SLightingUtilitiesPreviewPanel.h"

#include "Editor.h"
#include "LightingUtilitiesEditorSubsystem.h"

#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "SlateOptMacros.h"

#define LOCTEXT_NAMESPACE "LightingUtilitiesPreviewPanel"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SLightingUtilitiesPreviewPanel::Construct(const FArguments& InArgs)
{
	ModeOptions.Add(MakeShared<FString>(TEXT("Lights On")));
	ModeOptions.Add(MakeShared<FString>(TEXT("Lights Off")));
	ModeOptions.Add(MakeShared<FString>(TEXT("Dawn")));
	ModeOptions.Add(MakeShared<FString>(TEXT("Special Event")));
	SelectedMode = ModeOptions[0];

	ChildSlot
	[
		SNew(SBox)
		.Padding(12.f)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 0, 0, 4)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Title", "Lighting Utilities Preview"))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 0, 0, 10)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.ColorAndOpacity(FSlateColor::UseSubduedForeground())
				.Text(LOCTEXT("Warning",
					"Preview only. Applying a mode swaps materials on live actors in this editor "
					"session - it does not dirty or save the level. Hit Revert before you're done, "
					"or don't save the level while a non-default mode is showing."))
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 0, 0, 8)
			[
				SNew(SComboBox<TSharedPtr<FString>>)
				.OptionsSource(&ModeOptions)
				.OnGenerateWidget(this, &SLightingUtilitiesPreviewPanel::OnGenerateModeWidget)
				.OnSelectionChanged(this, &SLightingUtilitiesPreviewPanel::OnModeSelectionChanged)
				.InitiallySelectedItem(SelectedMode)
				[
					SNew(STextBlock)
					.Text(this, &SLightingUtilitiesPreviewPanel::GetSelectedModeText)
				]
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0, 0, 0, 8)
			[
				SNew(SUniformGridPanel)
				.SlotPadding(FMargin(4.f, 0.f))

				+ SUniformGridPanel::Slot(0, 0)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.Text(LOCTEXT("Apply", "Apply"))
					.OnClicked(this, &SLightingUtilitiesPreviewPanel::OnApplyClicked)
				]

				+ SUniformGridPanel::Slot(1, 0)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.Text(LOCTEXT("Revert", "Revert"))
					.OnClicked(this, &SLightingUtilitiesPreviewPanel::OnRevertClicked)
				]

				+ SUniformGridPanel::Slot(2, 0)
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.Text(LOCTEXT("Reload", "Reload Data"))
					.OnClicked(this, &SLightingUtilitiesPreviewPanel::OnReloadClicked)
				]
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text(this, &SLightingUtilitiesPreviewPanel::GetStatusText)
			]
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

TSharedRef<SWidget> SLightingUtilitiesPreviewPanel::OnGenerateModeWidget(TSharedPtr<FString> InOption) const
{
	return SNew(STextBlock).Text(FText::FromString(*InOption));
}

void SLightingUtilitiesPreviewPanel::OnModeSelectionChanged(TSharedPtr<FString> NewSelection, ESelectInfo::Type SelectInfo)
{
	if (NewSelection.IsValid())
	{
		SelectedMode = NewSelection;
	}
}

FText SLightingUtilitiesPreviewPanel::GetSelectedModeText() const
{
	return SelectedMode.IsValid() ? FText::FromString(*SelectedMode) : FText::GetEmpty();
}

ELightingUtilityMode SLightingUtilitiesPreviewPanel::ModeFromString(const FString& InString)
{
	if (InString == TEXT("Lights Off")) return ELightingUtilityMode::LightsOff;
	if (InString == TEXT("Dawn")) return ELightingUtilityMode::Dawn;
	if (InString == TEXT("Special Event")) return ELightingUtilityMode::SpecialEvent;
	return ELightingUtilityMode::LightsOn;
}

FReply SLightingUtilitiesPreviewPanel::OnApplyClicked()
{
	if (GEditor && SelectedMode.IsValid())
	{
		if (ULightingUtilitiesEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<ULightingUtilitiesEditorSubsystem>())
		{
			Subsystem->SetLightingMode(ModeFromString(*SelectedMode));
		}
	}
	return FReply::Handled();
}

FReply SLightingUtilitiesPreviewPanel::OnRevertClicked()
{
	if (GEditor)
	{
		if (ULightingUtilitiesEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<ULightingUtilitiesEditorSubsystem>())
		{
			Subsystem->RevertToOriginalMaterials();
		}
	}
	return FReply::Handled();
}

FReply SLightingUtilitiesPreviewPanel::OnReloadClicked()
{
	if (GEditor)
	{
		if (ULightingUtilitiesEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<ULightingUtilitiesEditorSubsystem>())
		{
			Subsystem->ReloadData();
		}
	}
	return FReply::Handled();
}

FText SLightingUtilitiesPreviewPanel::GetStatusText() const
{
	if (!GEditor)
	{
		return FText::GetEmpty();
	}

	if (const ULightingUtilitiesEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<ULightingUtilitiesEditorSubsystem>())
	{
		return FText::Format(
			LOCTEXT("Status", "{0} mesh list(s) loaded. Pending overrides this session: {1}."),
			FText::AsNumber(Subsystem->GetLoadedEntryCount()),
			Subsystem->HasPendingOverrides() ? LOCTEXT("Yes", "yes") : LOCTEXT("No", "no"));
	}

	return FText::GetEmpty();
}

#undef LOCTEXT_NAMESPACE
