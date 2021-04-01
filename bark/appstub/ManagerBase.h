#ifndef __BARK_APP___MANAGER_BASE_H__
#define __BARK_APP___MANAGER_BASE_H__

#include "../Debug.h"
#include "../Export.h"
#include "../Manager.h"
#include "BladeEntry.h"



namespace bark
{
    namespace app
    {
        class LoggerBase;
        class SpecimenBase;

        class BARK_EXPORT ManagerBase
        {
        public:
            ManagerBase(
                bark::core::Manager*    manager_core,
                LoggerBase*             logger);

            virtual ~ManagerBase() {}

            // called once
            void SetSpecimen(
                SpecimenBase* specimen) { m_specimen = specimen; }

            const char* GetBladesDirectory();

            void SetBladesDirectory(
                const char* directory);

            virtual void RefreshEntries();

            virtual bool LoadBlade(
                const char* name);

            void AddEntry(
                bark::core::BladeEntry* entry);

            bark::core::BladeEntry* GetEntry(
                unsigned int index);

            bark::core::BladeEntry* GetEntry(
                const char* name);

            unsigned int GetEntryCount();

            bark::core::BladeDeployment* GetDeployment(
                unsigned int index);

            bark::core::BladeDeployment* GetDeployment(
                const char* name);

            unsigned int GetDeploymentCount();

            virtual bool DeployBlade(
                bark::core::BladeEntry* entry);

            virtual void CloseBlade(
                bark::core::BladeDeployment* deployment);

            void CloseAllBlades();

            virtual void Broadcast(
                bark::core::BLADE_UPDATE    update,
                uint64_t                    val1,
                uint64_t                    val2,
                void*                       ptr);

        protected:
            bark::core::Manager*    m_manager_core;
            LoggerBase*             m_logger;
            SpecimenBase*           m_specimen;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___MANAGER_BASE_H__