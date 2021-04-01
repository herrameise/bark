#ifndef __BLADE_CORE___BLADE_TEMPLATE___LOADER_H__
#define __BLADE_CORE___BLADE_TEMPLATE___LOADER_H__

#include <bark/Blade.h>
using namespace bark::core;



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    BARK_EXPORT BladeMetadata* GetMetadata();

    BARK_EXPORT Blade* CreateBladeCore(
        Logger*     logger,
        Manager*    manager,
        Specimen*   specimen);

    BARK_EXPORT void DestroyBladeCore(
        Blade* blade);

#ifdef __cplusplus
}
#endif // __cplusplus



#endif // __BLADE_CORE___BLADE_TEMPLATE___LOADER_H__