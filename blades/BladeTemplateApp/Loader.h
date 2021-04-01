#ifndef __BLADE_APP___BLADE_TEMPLATE___LOADER_H__
#define __BLADE_APP___BLADE_TEMPLATE___LOADER_H__

#include <bark/appstub/Blade.h>
#include <bark/Export.h>
using namespace bark::app;



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    BARK_EXPORT Blade* CreateBladeApp(
        bark::core::Blade*  blade_core,
        LoggerBase*         logger,
        ManagerBase*        manager,
        SpecimenBase*       specimen);

    BARK_EXPORT void DestroyBladeApp(
        Blade* blade);

#ifdef __cplusplus
}
#endif // __cplusplus



#endif // __BLADE_APP___BLADE_TEMPLATE___LOADER_H__