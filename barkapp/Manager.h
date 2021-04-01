#ifndef __BARK_APP___MANAGER_H__
#define __BARK_APP___MANAGER_H__

class wxAuiManager;

#include <bark/appstub/ManagerBase.h>



namespace bark
{
    namespace app
    {
        class MainWindow;
        class Logger;

        class Manager : public ManagerBase
        {
        public:
            Manager(
                bark::core::Manager*    manager_core,
                Logger*                 logger,
                MainWindow*             main_window,
                wxAuiManager*           aui_manager);

            ~Manager() {}

            bool LoadBlade(
                const char* name) override;

            bool DeployBlade(
                bark::core::BladeEntry* entry) override;

            void CloseBlade(
                bark::core::BladeDeployment* deployment) override;

            void Broadcast(
                bark::core::BLADE_UPDATE    update,
                uint64_t                    val1,
                uint64_t                    val2,
                void*                       ptr) override;

            void LoadInternalBlades();

            void LaunchDeployBladeDialog();

        private:
            MainWindow*     m_main_window;
            wxAuiManager*   m_aui_manager;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___MANAGER_H__