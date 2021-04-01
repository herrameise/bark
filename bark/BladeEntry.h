#ifndef __BARK_CORE___BLADE_ENTRY_H__
#define __BARK_CORE___BLADE_ENTRY_H__

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#include "Export.h"



namespace bark
{
    namespace app
    {
        class BladeEntry;
    }

    namespace core
    {
        class Blade;
        class BladeMetadata;
        class Logger;
        class Manager;
        class Specimen;

#ifdef _WIN32
        typedef BladeMetadata*  (__cdecl *GET_METADATA_CORE_FN)     ();
        typedef Blade*          (__cdecl *CREATE_BLADE_CORE_FN)     (Logger*, Manager*, Specimen*);
        typedef void            (__cdecl *DESTROY_BLADE_CORE_FN)    (Blade*);
#else // Linux/OSX
        typedef BladeMetadata*  (*GET_METADATA_CORE_FN)             ();
        typedef Blade*          (*CREATE_BLADE_CORE_FN)             (Logger*, Manager*, Specimen*);
        typedef void            (*DESTROY_BLADE_CORE_FN)            (Blade*);
#endif // _WIN32

        class BARK_EXPORT BladeEntry
        {
        public:
            BladeEntry();

            ~BladeEntry();

            bark::app::BladeEntry*  app_component;

            BladeMetadata*          metadata;
#ifdef _WIN32
            HMODULE                 handle;
#else // Linux/OSX
            void*                   handle;
#endif // _WIN32
            CREATE_BLADE_CORE_FN    CreateBladeCore;
            DESTROY_BLADE_CORE_FN   DestroyBladeCore;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___BLADE_ENTRY_H__