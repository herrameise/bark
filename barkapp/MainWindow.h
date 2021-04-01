#ifndef __BARK_APP___MAIN_WINDOW_H__
#define __BARK_APP___MAIN_WINDOW_H__

#include <wx/string.h>

#include "MainWindowForms.h"



namespace bark
{
    namespace core
    {
        class Bark;
    }

    namespace app
    {
        class Logger;
        class Manager;
        class Specimen;

        class MainWindow : public MainWindowForm
        {
        public:
            MainWindow();

            ~MainWindow();

            bark::core::Bark* GetBarkCore() { return m_bark_core; }
            Logger* GetLogger() { return m_logger; }
            Manager* GetManager() { return m_manager; }
            Specimen* GetSpecimen() { return m_specimen; }

            void UpdateTitle(
                wxString filename);

            void UpdateStatusBarStatus(
                wxString status);

            void UpdateStatusBarSelectionRange(
                uint32_t start,
                uint32_t stop);

            void OnMenuFileLoadSpecimen(wxCommandEvent& event) override;
            void OnMenuFileExit(wxCommandEvent& event) override;
            void OnMenuBladesDeploy(wxCommandEvent& event) override;
            void OnMenuHelpAbout(wxCommandEvent& event) override;

            void BindEvents();

            void OnClose(
                wxCloseEvent& event);

        private:
            bark::core::Bark*   m_bark_core;
            Logger*             m_logger;
            Manager*            m_manager;
            Specimen*           m_specimen;
        };

    } // namespace "app"
} // namespace "bark"



#endif  // __BARK_APP___MAIN_WINDOW_H__