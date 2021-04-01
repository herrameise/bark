#ifndef __BARK_APP___LOGGER_BASE_H__
#define __BARK_APP___LOGGER_BASE_H__

#include "../Export.h"
#include "../Logger.h"



namespace bark
{
    namespace app
    {
        class BARK_EXPORT LoggerBase
        {
        public:
            LoggerBase(
                bark::core::Logger* logger_core);

            virtual ~LoggerBase() {}

            bark::core::LOGGER_LEVEL GetLevel();

            void SetLevel(
                bark::core::LOGGER_LEVEL level);

            void RegisterSource(
                void*           fptr,
                const char*     name);

            virtual void Log(
                void*                       source,
                bark::core::LOGGER_LEVEL    level,
                const char*                 message);

            void LogError(
                void*           source,
                const char*     message)
            {
                Log(source, bark::core::LOGGER_LEVEL_ERROR, message);
            }

            void LogWarning(
                void*           source,
                const char*     message)
            {
                Log(source, bark::core::LOGGER_LEVEL_WARNING, message);
            }

            void LogInfo(
                void*           source,
                const char*     message)
            {
                Log(source, bark::core::LOGGER_LEVEL_INFO, message);
            }

            void LogDebug(
                void*           source,
                const char*     message)
            {
                Log(source, bark::core::LOGGER_LEVEL_DEBUG, message);
            }

        protected:
            bark::core::Logger* m_logger_core;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___LOGGER_BASE_H__