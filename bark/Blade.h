#ifndef __BARK_CORE___BLADE_H__
#define __BARK_CORE___BLADE_H__

#include "BladeMetadata.h"
#include "BladeUpdate.h"
#include "Export.h"

#include <cstdint>



namespace bark
{
    namespace app
    {
        class Blade;
    }

    namespace core
    {
        class Logger;
        class Manager;
        class Specimen;

        class BARK_EXPORT Blade
        {
        public:
            Blade(
                Logger*     logger,
                Manager*    manager,
                Specimen*   specimen);

            virtual ~Blade();

            bark::app::Blade* GetBladeApp() { return m_blade_app; }

            void SetBladeApp(
                bark::app::Blade* blade_app) { m_blade_app = blade_app; }

            // REDIRECTOR
            void Update(
                BLADE_UPDATE    update,
                uint64_t        val1,
                uint64_t        val2,
                void*           ptr);

            virtual void UpdateCore(
                BLADE_UPDATE    update,
                uint64_t        val1,
                uint64_t        val2,
                void*           ptr) = 0;

        private:
            bark::app::Blade*       m_blade_app;
            Logger*                 m_logger;
            Manager*                m_manager;
            Specimen*               m_specimen;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___BLADE_H__