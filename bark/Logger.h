#ifndef __BARK_CORE___LOGGER_H__
#define __BARK_CORE___LOGGER_H__

#include "Export.h"



namespace bark
{
    namespace app
    {
        class LoggerBase;
    }

    namespace core
    {
        class LoggerOpaque;

        typedef enum LOGGER_LEVEL
        {
            LOGGER_LEVEL_NONE = 0,
            LOGGER_LEVEL_ERROR = 1,
            LOGGER_LEVEL_WARNING = 2,
            LOGGER_LEVEL_INFO = 3,
            LOGGER_LEVEL_DEBUG = 4,
            LOGGER_LEVEL_ALL = 5
        } LOGGER_LEVEL;

        class BARK_EXPORT Logger
        {
        public:
            Logger();

            ~Logger();

            void SetAppComponent(
                bark::app::LoggerBase* app_component) { m_app_component = app_component; }

            LOGGER_LEVEL GetLevel() { return m_level; }

            void SetLevel(
                LOGGER_LEVEL level) { m_level = level; }

            void RegisterSource(
                void*           fptr,
                const char*     name);

            const char* TranslateSource(
                void* fptr);

            // REDIRECTOR
            void Log(
                void*           source,
                LOGGER_LEVEL    level,
                const char*     message);

            void LogCore(
                void*           source,
                LOGGER_LEVEL    level,
                const char*     message);

            void LogError(
                void*           source,
                const char*     message)
            {
                Log(source, LOGGER_LEVEL_ERROR, message);
            }

            void LogWarning(
                void*           source,
                const char*     message)
            {
                Log(source, LOGGER_LEVEL_WARNING, message);
            }

            void LogInfo(
                void*           source,
                const char*     message)
            {
                Log(source, LOGGER_LEVEL_INFO, message);
            }

            void LogDebug(
                void*           source,
                const char*     message)
            {
                Log(source, LOGGER_LEVEL_DEBUG, message);
            }

        private:
            LoggerOpaque*           m_opaque;
            bark::app::LoggerBase*  m_app_component;

            LOGGER_LEVEL            m_level;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___LOGGER_H__