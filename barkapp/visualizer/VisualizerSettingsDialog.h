#ifndef __BARK_APP___VISUALIZER_SETTINGS_DIALOG_H__
#define __BARK_APP___VISUALIZER_SETTINGS_DIALOG_H__

#include "VisualizerForms.h"



namespace bark
{
    namespace app
    {
        class VisualizerPanel;
        class VisualizerSettings;

        class VisualizerSettingsDialog : public VisualizerSettingsDialogForm
        {
        public:
            VisualizerSettingsDialog(
                wxWindow*           parent,
                VisualizerPanel*    visualizer_panel);

            void OnButtonDefaults(wxCommandEvent& event);
            void OnButtonSave(wxCommandEvent& event);
            void OnButtonCancel(wxCommandEvent& event);

        private:
            VisualizerPanel*        m_visualizer_panel;
            VisualizerSettings*     m_settings;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___VISUALIZER_SETTINGS_DIALOG_H__