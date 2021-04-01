#ifndef __BARK_CORE___BARK_H__
#define __BARK_CORE___BARK_H__

#include "Export.h"
#include "Version.h"



namespace bark
{
    namespace core
    {
        class Logger;
        class Manager;
        class Specimen;

        class BARK_EXPORT Bark
        {
        public:
            Bark();

            ~Bark();

            bool Initialize();

            Logger* GetLogger() { return m_logger; }

            Manager* GetManager() { return m_manager; }

            Specimen* GetSpecimen() { return m_specimen; }

            unsigned int GetVersionMajor() { return BARK_CORE_VERSION_MAJOR; }

            unsigned int GetVersionMinor() { return BARK_CORE_VERSION_MINOR; }

            unsigned int GetVersionPatch() { return BARK_CORE_VERSION_PATCH; }

        private:
            Logger*     m_logger;
            Manager*    m_manager;
            Specimen*   m_specimen;
        };
        
    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___BARK_H__