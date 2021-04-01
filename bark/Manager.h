#ifndef __BARK_CORE___MANAGER_H__
#define __BARK_CORE___MANAGER_H__

#include "Blade.h"
#include "BladeDeployment.h"
#include "BladeEntry.h"
#include "Export.h"



namespace bark
{
    namespace app
    {
        class ManagerBase;
    }

    namespace core
    {
        class ManagerOpaque;
        class Logger;
        class Specimen;

        class BARK_EXPORT Manager
        {
        public:
            Manager(
                Logger* logger);

            ~Manager();

            void SetAppComponent(
                bark::app::ManagerBase* app_component) { m_app_component = app_component; }

            void SetSpecimen(
                Specimen* specimen) { m_specimen = specimen; }

            const char* GetBladesDirectory();

            void SetBladesDirectory(
                const char* directory);

            // REDIRECTOR
            void RefreshEntries(); 

            void RefreshEntriesCore();

            // REDIRECTOR
            bool LoadBlade(
                const char* name);

            bool LoadBladeCore(
                const char* name);

            void AddEntry(
                BladeEntry* entry);

            BladeEntry* GetEntry(
                unsigned int index);

            BladeEntry* GetEntry(
                const char* name);

            unsigned int GetEntryCount();

            BladeDeployment* GetDeployment(
                unsigned int index);

            BladeDeployment* GetDeployment(
                const char* name);

            unsigned int GetDeploymentCount();

            // REDIRECTOR
            bool DeployBlade(
                BladeEntry* entry);

            bool DeployBladeCore(
                BladeEntry* entry);

            // REDIRECTOR
            void CloseBlade(
                BladeDeployment* deployment);

            void CloseBladeCore(
                BladeDeployment* deployment);

            void CloseAllBlades();

            // REDIRECTOR
            void Broadcast(
                BLADE_UPDATE    update,
                uint64_t        val1,
                uint64_t        val2,
                void*           ptr);

            void BroadcastCore(
                BLADE_UPDATE    update,
                uint64_t        val1,
                uint64_t        val2,
                void*           ptr);

        private:
            ManagerOpaque*              m_opaque;
            bark::app::ManagerBase*     m_app_component;
            Logger*                     m_logger;
            Specimen*                   m_specimen;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___MANAGER_H__