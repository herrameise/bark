#ifndef __BARK_APP___DEPLOY_BLADE_DIALOG_H__
#define __BARK_APP___DEPLOY_BLADE_DIALOG_H__

#include "ManagerForms.h"



namespace bark
{
    namespace app
    {
        class Manager;

        class DeployBladeDialog : public DeployBladeDialogForm
        {
        public:
            DeployBladeDialog(
                Manager* manager);

            ~DeployBladeDialog() {}

            inline BladeEntriesListCtrl* GetBladeEntriesListCtrl();

            void RefreshBladeEntriesListCtrl();

            void OnButtonDeploy(wxCommandEvent& event) override;
            void OnButtonClose(wxCommandEvent& event) override;

        private:
            Manager* m_manager;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___DEPLOY_BLADE_DIALOG_H__