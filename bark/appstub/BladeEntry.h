#ifndef __BARK_APP___BLADE_ENTRY_H__
#define __BARK_APP___BLADE_ENTRY_H__

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#include "../Export.h"



namespace bark
{
    namespace core
    {
        class Blade;
    }

    namespace app
    {
        class Blade;
        class LoggerBase;
        class ManagerBase;
        class SpecimenBase;

#ifdef _WIN32
        typedef Blade*      (__cdecl *CREATE_BLADE_APP_FN)      (bark::core::Blade*, LoggerBase*, ManagerBase*, SpecimenBase*);
        typedef void        (__cdecl *DESTROY_BLADE_APP_FN)     (Blade*);
#else // Linux/OSX
        typedef Blade*      (*CREATE_BLADE_APP_FN)              (bark::core::Blade*, LoggerBase*, ManagerBase*, SpecimenBase*);
        typedef void        (*DESTROY_BLADE_APP_FN)             (Blade*);
#endif // _WIN32

        class BARK_EXPORT BladeEntry
        {
        public:
            BladeEntry() {}

            virtual ~BladeEntry() {}

#ifdef _WIN32
            HMODULE                 handle;
#else // Linux/OSX
            void*                   handle;
#endif // _WIN32
            CREATE_BLADE_APP_FN     CreateBladeApp;
            DESTROY_BLADE_APP_FN    DestroyBladeApp;
        };
    }
}

#endif // __BARK_APP___BLADE_ENTRY_H__