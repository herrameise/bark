#ifndef __BARK_CORE_CBIND___LOGGER_H__
#define __BARK_CORE_CBIND___LOGGER_H__

#include "Export.h"



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    typedef enum LOGGER_LEVEL
    {
        LOGGER_LEVEL_NONE = 0,
        LOGGER_LEVEL_ERROR = 1,
        LOGGER_LEVEL_WARNING = 2,
        LOGGER_LEVEL_INFO = 3,
        LOGGER_LEVEL_DEBUG = 4,
        LOGGER_LEVEL_ALL = 5
    } LOGGER_LEVEL;

    struct Logger
    {
        void* opaque;
    };

    BARK_CBIND_EXPORT LOGGER_LEVEL Logger_GetLevel(
        struct Logger*  logger);

    BARK_CBIND_EXPORT void Logger_SetLevel(
        struct Logger*  logger,
        LOGGER_LEVEL    level);

    BARK_CBIND_EXPORT void Logger_Log(
        struct Logger*  logger,
        void*           source,
        LOGGER_LEVEL    level,
        const char*     message);

    BARK_CBIND_EXPORT void Logger_LogError(
        struct Logger*  logger,
        void*           source,
        const char*     message);

    BARK_CBIND_EXPORT void Logger_LogWarning(
        struct Logger*  logger,
        void*           source,
        const char*     message);

    BARK_CBIND_EXPORT void Logger_LogInfo(
        struct Logger*  logger,
        void*           source,
        const char*     message);

    BARK_CBIND_EXPORT void Logger_LogDebug(
        struct Logger*  logger,
        void*           source,
        const char*     message);

#ifdef __cplusplus
}
#endif // __cplusplus



#endif // __BARK_CORE_CBIND___LOGGER_H__