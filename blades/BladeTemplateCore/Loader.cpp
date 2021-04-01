#include "Loader.h"

#include "Blade.h"
using namespace blade::blade_template::core;

class BladeMetadata metadata;



BladeMetadata* GetMetadata()
{
    metadata.name = "Blade Template";
    metadata.author = "DZ Labs";
    metadata.version_major = 0;
    metadata.version_minor = 1;
    metadata.version_patch = 0;
    metadata.build_date = __DATE__;
    metadata.build_time = __TIME__;

    return &metadata;
}


Blade* CreateBladeCore(
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen)
{
    return new BladeTemplate(logger, manager, specimen);
}


void DestroyBladeCore(
    Blade* blade)
{
    BladeTemplate* blade_template = static_cast<BladeTemplate*>(blade);
    delete blade_template;
}