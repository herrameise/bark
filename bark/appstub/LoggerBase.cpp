#include "LoggerBase.h"
using namespace bark::app;



LoggerBase::LoggerBase(
    bark::core::Logger* logger_core) :
    m_logger_core(logger_core)
{
    m_logger_core->SetAppComponent(this);
}


bark::core::LOGGER_LEVEL LoggerBase::GetLevel()
{
    return m_logger_core->GetLevel();
}


void LoggerBase::SetLevel(
    bark::core::LOGGER_LEVEL level)
{
    m_logger_core->SetLevel(level);
}


void LoggerBase::RegisterSource(
    void*           fptr,
    const char*     name)
{
    m_logger_core->RegisterSource(fptr, name);
}


// virtual function
void LoggerBase::Log(
    void*                       source,
    bark::core::LOGGER_LEVEL    level,
    const char*                 message)
{
    m_logger_core->Log(source, level, message);
}