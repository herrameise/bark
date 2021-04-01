#include "Logger.h"
#include "LoggerOpaque.h"
using namespace bark::core;

#include "appstub/LoggerBase.h"

#include <cstdio>



Logger::Logger() :
    m_app_component(nullptr)
{
    m_opaque = new LoggerOpaque();
    SetLevel(LOGGER_LEVEL_ALL);
}


Logger::~Logger()
{
    delete m_opaque;
}


void Logger::RegisterSource(
    void*           fptr,
    const char*     name)
{
    m_opaque->sources[fptr] = string(name);
}


const char* Logger::TranslateSource(
    void* fptr)
{
    return m_opaque->sources[fptr].c_str();
}


void Logger::Log(
    void*           source,
    LOGGER_LEVEL    level,
    const char*     message)
{
    if (m_app_component) { m_app_component->Log(source, level, message); }
    else LogCore(source, level, message);
}


void Logger::LogCore(
    void*           source,
    LOGGER_LEVEL    level,
    const char*     message)
{
    // only display messages above minimum log level
    if (level > m_level) return;

    switch (level)
    {
    case LOGGER_LEVEL_NONE:
        break;
    case LOGGER_LEVEL_ERROR:
        fprintf(stderr, "[<!>] %s : %s\n", m_opaque->sources[source].c_str(), message);
        break;
    case LOGGER_LEVEL_WARNING:
        fprintf(stderr, "[ ! ] %s : %s\n", m_opaque->sources[source].c_str(), message);
        break;
    case LOGGER_LEVEL_INFO:
        printf("[ + ] %s : %s\n", m_opaque->sources[source].c_str(), message);
        break;
    case LOGGER_LEVEL_DEBUG:
        printf("[ * ] %s : %s\n", m_opaque->sources[source].c_str(), message);
        break;
    default:
        break;
    }
}