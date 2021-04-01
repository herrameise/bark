#ifndef __BARK_APP___EDITOR_SETTINGS_DIALOG_H__
#define __BARK_APP___EDITOR_SETTINGS_DIALOG_H__

#include "EditorForms.h"
#include "EditorSettings.h"



namespace bark
{
    namespace app
    {
        class EditorPanel;

        class EditorSettingsDialog : public EditorSettingsDialogForm
        {
        public:
            EditorSettingsDialog(
                wxWindow*       parent,
                EditorPanel*    editor_panel);

            void OnButtonSave(wxCommandEvent& event);
            void OnButtonCancel(wxCommandEvent& event);

        private:
            EditorPanel*        m_editor_panel;
            EditorSettings*     m_settings;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___EDITOR_SETTINGS_DIALOG_H__