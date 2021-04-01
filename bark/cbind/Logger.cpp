#include "Logger.h"
#include "../Logger.h"



LOGGER_LEVEL Logger_GetLevel(
    struct Logger*  logger)
{
    bark::core::Logger* opaque = reinterpret_cast<bark::core::Logger*>(logger->opaque);
    return static_cast<LOGGER_LEVEL>(opaque->GetLevel());
}


void Logger_SetLevel(
    struct Logger*  logger,
    LOGGER_LEVEL    level)
{
    bark::core::Logger* opaque = reinterpret_cast<bark::core::Logger*>(logger->opaque);
    opaque->SetLevel(static_cast<bark::core::LOGGER_LEVEL>(level));
}


void Logger_Log(
    struct Logger*  logger,
    void*           source,
    LOGGER_LEVEL    level,
    const char*     message)
{
    bark::core::Logger* opaque = reinterpret_cast<bark::core::Logger*>(logger->opaque);
    opaque->Log(source, static_cast<bark::core::LOGGER_LEVEL>(level), message);
}


void Logger_LogError(
    struct Logger*  logger,
    void*           source,
    const char*     message)
{
    Logger_Log(logger, source, LOGGER_LEVEL_ERROR, message);
}


void Logger_LogWarning(
    struct Logger*  logger,
    void*           source,
    const char*     message)
{
    Logger_Log(logger, source, LOGGER_LEVEL_WARNING, message);
}


void Logger_LogInfo(
    struct Logger*  logger,
    void*           source,
    const char*     message)
{
    Logger_Log(logger, source, LOGGER_LEVEL_INFO, message);
}


void Logger_LogDebug(
    struct Logger*  logger,
    void*           source,
    const char*     message)
{
    Logger_Log(logger, source, LOGGER_LEVEL_DEBUG, message);
}