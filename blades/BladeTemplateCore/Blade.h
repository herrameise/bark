#ifndef __BLADE_CORE___BLADE_TEMPLATE___BLADE_H__
#define __BLADE_CORE___BLADE_TEMPLATE___BLADE_H__

#include <bark/Blade.h>
using namespace bark::core;



namespace blade
{
    namespace blade_template
    {
        namespace core
        {
            class BladeTemplate : public Blade
            {
            public:
                BladeTemplate(
                    Logger*     logger,
                    Manager*    manager,
                    Specimen*   specimen);

                ~BladeTemplate();

                void UpdateCore(
                    BLADE_UPDATE    update,
                    uint64_t        val1,
                    uint64_t        val2,
                    void*           ptr) override;
            };
        }
    }
}



#endif // __BLADE_CORE___BLADE_TEMPLATE___BLADE_H__