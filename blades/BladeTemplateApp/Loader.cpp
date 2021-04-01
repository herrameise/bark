#include "Loader.h"

#include "Blade.h"
using namespace blade::blade_template::app;



Blade* CreateBladeApp(
    bark::core::Blade*  blade_core,
    LoggerBase*         logger,
    ManagerBase*        manager,
    SpecimenBase*       specimen)
{
    return new BladeTemplate(
        (blade::blade_template::core::BladeTemplate*)blade_core,
        (Logger*)logger, (Manager*)manager, (Specimen*)specimen);
}


void DestroyBladeApp(
    Blade* blade)
{
    BladeTemplate* blade_template = static_cast<BladeTemplate*>(blade);
    delete blade_template;
}