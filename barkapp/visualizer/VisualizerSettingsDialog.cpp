#include "VisualizerSettingsDialog.h"
using namespace bark::app;

#include "VisualizerPanel.h"
#include "VisualizerSettings.h"



VisualizerSettingsDialog::VisualizerSettingsDialog(
    wxWindow*           parent,
    VisualizerPanel*    visualizer_panel) :
    VisualizerSettingsDialogForm(parent),
    m_visualizer_panel(visualizer_panel)
{
    m_settings = m_visualizer_panel->GetSettings();

    m_ColorPickerNormalZero->SetColour(m_settings->normal_zero);
    m_ColorPickerNormalOne->SetColour(m_settings->normal_one);
    m_ColorPickerSelectionZero->SetColour(m_settings->selection_zero);
    m_ColorPickerSelectionOne->SetColour(m_settings->selection_one);

    m_SpinCtrlSnap->SetBase(10);
    m_SpinCtrlSnap->SetRange(1, 64);
    m_SpinCtrlSnap->SetValue(m_settings->snap);
    m_CheckBoxSeparators->SetValue(m_settings->show_separators);

    // bind events
    m_ButtonDefaults->Bind(wxEVT_BUTTON, &VisualizerSettingsDialog::OnButtonDefaults, this);
    m_ButtonSave->Bind(wxEVT_BUTTON, &VisualizerSettingsDialog::OnButtonSave, this);
    m_ButtonCancel->Bind(wxEVT_BUTTON, &VisualizerSettingsDialog::OnButtonCancel, this);
}


void VisualizerSettingsDialog::OnButtonDefaults(
    wxCommandEvent& event)
{
    m_ColorPickerNormalZero->SetColour(*wxWHITE);
    m_ColorPickerNormalOne->SetColour(*wxBLACK);
    m_ColorPickerSelectionZero->SetColour(*wxCYAN);
    m_ColorPickerSelectionOne->SetColour(*wxBLUE);
}


void VisualizerSettingsDialog::OnButtonSave(
    wxCommandEvent& event)
{
    m_settings->normal_zero = m_ColorPickerNormalZero->GetColour();
    m_settings->normal_one = m_ColorPickerNormalOne->GetColour();
    m_settings->selection_zero = m_ColorPickerSelectionZero->GetColour();
    m_settings->selection_one = m_ColorPickerSelectionOne->GetColour();
    m_settings->snap = m_SpinCtrlSnap->GetValue();
    m_settings->show_separators = m_CheckBoxSeparators->GetValue();

    Destroy();
}


void VisualizerSettingsDialog::OnButtonCancel(
    wxCommandEvent& event)
{
    Destroy();
}
