#include "Specimen.h"
using namespace bark::app;

#include <cstring>

#include <bark/appstub/ManagerBase.h>
#include <bark/Specimen.h>

#include "Logger.h"
#include "MainWindow.h"



Specimen::Specimen(
    bark::core::Specimen*   specimen_core,
    Logger*                 logger,
    Manager*                manager,
    MainWindow*             main_window) :
    SpecimenBase(specimen_core, (bark::app::LoggerBase*)logger, (bark::app::ManagerBase*)manager),
    m_main_window(main_window)
{
    m_logger->RegisterSource(this, "Specimen [app]");
}


bool Specimen::LoadFile(
    const char*                 filename,
    bark::core::SPECIMEN_MODE   mode)
{
    if (m_specimen_core->LoadFileCore(filename, mode) == false) { return false; }

    m_main_window->UpdateTitle(m_specimen_core->GetName());
    return true;
}


void Specimen::ClearSelection()
{
    // clear in window

    m_specimen_core->ClearSelectionCore();
}


void Specimen::SetSelection(
    uint64_t    start_byte,
    uint8_t     start_bit,
    uint64_t    stop_byte,
    uint8_t     stop_bit)
{
    m_main_window->UpdateStatusBarSelectionRange(
        start_byte,
        stop_byte);

    m_specimen_core->SetSelectionCore(
        start_byte, start_bit,
        stop_byte, stop_bit);
}


void Specimen::SetSelection(
    unsigned int    packet,
    uint64_t        start_byte,
    uint8_t         start_bit,
    uint64_t        stop_byte,
    uint8_t         stop_bit)
{
    m_main_window->UpdateStatusBarSelectionRange(
        start_byte,
        stop_byte);

    m_specimen_core->SetSelectionCore(
        packet,
        start_byte, start_bit,
        stop_byte, stop_bit);
}
