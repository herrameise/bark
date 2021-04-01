#include "Logger.h"
using namespace bark::app;

#include <wx/window.h>

#include "LoggerPanel.h"



Logger::Logger(
    bark::core::Logger* logger_core) :
    LoggerBase(logger_core),
    m_panel(nullptr) {}


Logger::~Logger()
{
    if (m_panel) DestroyPanel();
}


void Logger::Log(
    void*                       source,
    bark::core::LOGGER_LEVEL    level,
    const char*                 message)
{
    m_logger_core->LogCore(source, level, message);
    m_panel->Log(level, m_logger_core->TranslateSource(source), message);
}


bool Logger::CreatePanel(wxWindow* parent)
{
    if (m_panel) return false;

    m_panel = new LoggerPanel(parent);
    if (m_panel == nullptr) return false;

    return true;
}


wxWindow* Logger::GetPanel()
{
    return m_panel;
}


void Logger::DestroyPanel()
{
    m_panel->Destroy();
    m_panel = nullptr;
}
