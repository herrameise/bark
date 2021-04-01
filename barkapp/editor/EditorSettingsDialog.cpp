#include "EditorSettingsDialog.h"
using namespace bark::app;

#include "EditorPanel.h"
#include "EditorSettings.h"



EditorSettingsDialog::EditorSettingsDialog(
    wxWindow*       parent,
    EditorPanel*    editor_panel) :
    EditorSettingsDialogForm(parent),
    m_editor_panel(editor_panel)
{
    m_settings = m_editor_panel->GetSettings();

    // build font wxComboBox
    wxArrayString& facenames = m_settings->facenames;
    for (size_t i = 0; i < m_settings->facenames.GetCount(); i++)
    {
        wxFont font;
        font.SetFaceName(facenames[i]);
        if (font.IsFixedWidth()) m_ComboBoxFontFaceName->Append(facenames[i]);
    }

    // set controls to current values
    m_ComboBoxFontFaceName->SetSelection(m_ComboBoxFontFaceName->FindString(m_settings->font.GetFaceName()));
    m_ComboBoxFontPointSize->SetSelection(m_ComboBoxFontPointSize->FindString(wxString::Format("%d", m_settings->font.GetPointSize())));
    if (m_settings->capital_hex == false) { m_RadioBoxCapitalization->SetSelection(0); }
    else { m_RadioBoxCapitalization->SetSelection(1); }

    // bind event handlers
    m_SaveButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &EditorSettingsDialog::OnButtonSave, this);
    m_CancelButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &EditorSettingsDialog::OnButtonCancel, this);
}


void EditorSettingsDialog::OnButtonSave(
    wxCommandEvent& event)
{
    m_settings->font.SetFaceName(m_ComboBoxFontFaceName->GetStringSelection());
    m_settings->font.SetPointSize(wxAtoi(m_ComboBoxFontPointSize->GetStringSelection()));
    m_settings->capital_hex = static_cast<bool>(m_RadioBoxCapitalization->GetSelection());

    Destroy();
}


void EditorSettingsDialog::OnButtonCancel(
    wxCommandEvent& event)
{
    Destroy();
}