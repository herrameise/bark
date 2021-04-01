#include "LoggerPanel.h"
using namespace bark::app;



LoggerPanel::LoggerPanel(
    wxWindow* parent) :
    LoggerPanelForm(parent) {}
    

LoggerPanel::~LoggerPanel() {}


void LoggerPanel::Log(
    bark::core::LOGGER_LEVEL    level,
    const char*                 source,
    const char*                 message)
{
    switch (level)
    {
    case bark::core::LOGGER_LEVEL_ERROR:
        m_RichTextCtrl->BeginTextColour(*wxRED);
        m_RichTextCtrl->WriteText(wxString("[<!>] ") + wxString(source) + wxString(" : ") + wxString(message) + wxString("\n"));
        m_RichTextCtrl->EndTextColour();
        break;
    case bark::core::LOGGER_LEVEL_WARNING:
        m_RichTextCtrl->BeginTextColour(*wxYELLOW);
        m_RichTextCtrl->WriteText(wxString("[ ! ] ") + wxString(source) + wxString(" : ") + wxString(message) + wxString("\n"));
        m_RichTextCtrl->EndTextColour();
        break;
    case bark::core::LOGGER_LEVEL_INFO:
        m_RichTextCtrl->BeginTextColour(*wxGREEN);
        m_RichTextCtrl->WriteText(wxString("[ + ] ") + wxString(source) + wxString(" : ") + wxString(message) + wxString("\n"));
        m_RichTextCtrl->EndTextColour();
        break;
    case bark::core::LOGGER_LEVEL_DEBUG:
        m_RichTextCtrl->BeginTextColour(*wxWHITE);
        m_RichTextCtrl->WriteText(wxString("[ * ] ") + wxString(source) + wxString(" : ") + wxString(message) + wxString("\n"));
        m_RichTextCtrl->EndTextColour();
        break;
    default:
        break;
    }
}