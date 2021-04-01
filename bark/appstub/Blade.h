#ifndef __BARK_APP___BLADE_H__
#define __BARK_APP___BLADE_H__

#include <cstdint>

#include "../Blade.h"
#include "../Export.h"



namespace bark
{
    namespace app
    {
        class LoggerBase;
        class ManagerBase;
        class SpecimenBase;

        class BARK_EXPORT Blade
        {
        public:
            Blade(
                bark::core::Blade*  blade_core,
                LoggerBase*         logger,
                ManagerBase*        manager,
                SpecimenBase*       specimen);

            virtual ~Blade() {}

            virtual bool CreateUserInterface(
                void* parent) { return false; }

            void* GetUserInterface() { return m_ui; }

            virtual void DestroyUserInterface() {}

            virtual void Update(
                bark::core::BLADE_UPDATE    update,
                uint64_t                    val1,
                uint64_t                    val2,
                void*                       ptr);

        protected:
            bark::core::Blade*  m_blade_core;

            LoggerBase*         m_logger;
            ManagerBase*        m_manager;
            SpecimenBase*       m_specimen;

            void*               m_ui;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_APP___BLADE_H__