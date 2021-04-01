#ifndef __BLADE_APP___BLADE_TEMPLATE___BLADE_H__
#define __BLADE_APP___BLADE_TEMPLATE___BLADE_H__

#include <bark/appstub/Blade.h>
using namespace bark::app;

namespace bark
{
    namespace app
    {
        class Logger;
        class Manager;
        class Specimen;
    }
}



namespace blade
{
    namespace blade_template
    {
        namespace core
        {
            class BladeTemplate;
        }

        namespace app
        {
            class BladeTemplate : public Blade
            {
            public:
                BladeTemplate(
                    blade::blade_template::core::BladeTemplate* blade_core,
                    Logger*         logger,
                    Manager*        manager,
                    Specimen*       specimen);

                ~BladeTemplate();

                bool CreateUserInterface(
                    void* parent) override;

                void DestroyUserInterface() override;

                void Update(
                    bark::core::BLADE_UPDATE    update,
                    uint64_t                    val1,
                    uint64_t                    val2,
                    void*                       ptr) override;
            };
        }
    }
}



#endif // __BLADE_APP___BLADE_TEMPLATE___BLADE_H__