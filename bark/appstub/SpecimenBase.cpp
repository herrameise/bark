#include "SpecimenBase.h"
using namespace bark::app;



SpecimenBase::SpecimenBase(
    bark::core::Specimen*   specimen_core,
    LoggerBase*             logger,
    ManagerBase*            manager) :
    m_specimen_core(specimen_core),
    m_logger(logger),
    m_manager(manager)
{
    m_specimen_core->SetAppComponent(this);
}


bool SpecimenBase::Exists()
{
    return m_specimen_core->Exists();
}


bark::core::SPECIMEN_MODE SpecimenBase::GetMode()
{
    return m_specimen_core->GetMode();
}


const char* SpecimenBase::GetName()
{
    return m_specimen_core->GetName();
}


void SpecimenBase::SetName(
    const char* name)
{
    m_specimen_core->SetName(name);
}


void SpecimenBase::Clear()
{
    m_specimen_core->Clear();
}


// virtual function
bool SpecimenBase::LoadFile(
    const char*                 filename,
    bark::core::SPECIMEN_MODE   mode)
{
    return m_specimen_core->LoadFileCore(filename, mode);
}


bool SpecimenBase::ParsePcap(
    uint64_t    length,
    uint8_t*    bytes)
{
    return m_specimen_core->ParsePcap(length, bytes);
}


uint8_t* SpecimenBase::GetRawData()
{
    return m_specimen_core->GetRawData();
}


uint64_t SpecimenBase::GetSize()
{
    return m_specimen_core->GetSize();
}


bool SpecimenBase::GetBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t*    buffer)
{
    return m_specimen_core->GetBytes(offset, size, buffer);
}


bool SpecimenBase::FillBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t     value)
{
    return m_specimen_core->FillBytes(offset, size, value);
}


bool SpecimenBase::ReplaceBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t*    bytes)
{
    return m_specimen_core->ReplaceBytes(offset, size, bytes);
}


bool SpecimenBase::InsertBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t*    bytes)
{
    return m_specimen_core->InsertBytes(offset, size, bytes);
}


bool SpecimenBase::DeleteBytes(
    uint64_t    offset,
    uint64_t    size)
{
    return m_specimen_core->DeleteBytes(offset, size);
}


bool SpecimenBase::SelectionExists()
{
    return m_specimen_core->SelectionExists();
}


unsigned int SpecimenBase::GetSelectionPacket()
{
    return m_specimen_core->GetSelectionPacket();
}


uint64_t SpecimenBase::GetSelectionStartByte()
{
    return m_specimen_core->GetSelectionStartByte();
}


uint8_t SpecimenBase::GetSelectionStartBit()
{
    return m_specimen_core->GetSelectionStartBit();
}


uint64_t SpecimenBase::GetSelectionStopByte()
{
    return m_specimen_core->GetSelectionStopByte();
}


uint8_t SpecimenBase::GetSelectionStopBit()
{
    return m_specimen_core->GetSelectionStopBit();
}


// virtual function
void SpecimenBase::ClearSelection()
{
    m_specimen_core->ClearSelectionCore();
}


// virtual function
void SpecimenBase::SetSelection(
    uint64_t    start_byte,
    uint8_t     start_bit,
    uint64_t    stop_byte,
    uint8_t     stop_bit)
{
    m_specimen_core->SetSelectionCore(
        start_byte, start_bit,
        stop_byte, stop_bit);
}


// virtual function
void SpecimenBase::SetSelection(
    unsigned int    packet,
    uint64_t        start_byte,
    uint8_t         start_bit,
    uint64_t        stop_byte,
    uint8_t         stop_bit)
{
    m_specimen_core->SetSelectionCore(
        packet,
        start_byte, start_bit,
        stop_byte, stop_bit);
}