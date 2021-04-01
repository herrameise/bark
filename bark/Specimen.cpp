#include "Specimen.h"
#include "SpecimenOpaque.h"
using namespace bark::core;

#include "appstub/SpecimenBase.h"
#include "Logger.h"
#include "Manager.h"
#include "Packet.h"

#include <cstdio>
#include <cstring>



Specimen::Specimen(
    Logger*     logger,
    Manager*    manager):
    m_app_component(nullptr),
    m_logger(logger),
    m_manager(manager)
{
    m_opaque = new SpecimenOpaque();
    m_logger->RegisterSource(this, "Specimen [core]");
    Clear();
}


Specimen::~Specimen()
{
    m_opaque->bytes.clear();
    delete m_opaque;
}


const char* Specimen::GetName()
{
    return m_opaque->name.c_str();
}


void Specimen::SetName(
    const char* name)
{
    m_opaque->name = string(name);
}


void Specimen::Clear()
{
    m_exists = false;
    m_opaque->name = "";
    m_opaque->bytes.clear();
    SetName("");
}


// REDIRECTOR
bool Specimen::LoadFile(
    const char*     filename,
    SPECIMEN_MODE   mode)
{
    if (m_app_component) { return m_app_component->LoadFile(filename, mode); }
    else { return LoadFileCore(filename, mode); }
}


bool Specimen::LoadFileCore(
    const char*     filename,
    SPECIMEN_MODE   mode)
{
    // open file
#ifdef _WIN32
    FILE* fp = fopen(filename, "rb");
#else // Linux/OSX
    FILE* fp = fopen(filename, "r");
#endif // _WIN32
    if (fp == NULL)
    {
        string message = "failed to open file: " + string(filename);
        m_logger->LogError(this, message.c_str());
        return false;
    }

    // get file size
#ifdef _WIN32
    _fseeki64(fp, 0L, SEEK_END);
    uint64_t filesize = (uint64_t)_ftelli64(fp);
#else // Linux/OSX
    fseeko(fp, 0L, SEEK_END);
    uint64_t filesize = (uint64_t)ftello(fp);
#endif // _WIN32
    rewind(fp);

    // allocate memory for bytes
    m_opaque->bytes.resize(filesize);
    if (m_opaque->bytes.size() != filesize)
    {
        m_logger->LogError(this, "failed to allocate sufficient memory for specimen");
        fclose(fp);
        return false;
    }

    // read bytes into memory
    unsigned int SIZEOF_MB = 1024 * 1024;
    uint64_t num_chunks = (filesize / SIZEOF_MB) + 1;
    for (unsigned int i = 0; i < num_chunks; i++)
    {
        uint64_t chunk_size = SIZEOF_MB;
        if (((i + 1) * SIZEOF_MB) > filesize) { chunk_size = filesize - (i * SIZEOF_MB); }
        size_t bytes_read = fread(&m_opaque->bytes.data()[i*SIZEOF_MB], 1, chunk_size, fp);
        if (bytes_read != chunk_size) { m_logger->LogWarning(this, "incorrect amount of bytes read"); }
    }

    // close file
    fclose(fp);

    if (mode == SPECIMEN_MODE_PACKET)
    {
        ParsePcap(m_opaque->bytes.size(), m_opaque->bytes.data());
    }

    m_opaque->name = filename;
    m_exists = true;

    string message = "loaded specimen from file: " + string(filename);
    m_logger->LogInfo(this, message.c_str());

    m_manager->Broadcast(BLADE_UPDATE_NEW, 0, 0, nullptr);

    return true;
}


bool Specimen::ParsePcap(
    uint64_t    length,
    uint8_t*    bytes)
{
    typedef struct pcap_hdr_s {
        uint32_t    magic_number;
        uint16_t    version_major;
        uint16_t    version_minor;
        int32_t     thiszone;
        uint32_t    sigfigs;
        uint32_t    snaplen;
        uint32_t    network;
    } pcap_hdr_t;

    typedef struct pcaprec_hdr_s {
        uint32_t    ts_sec;
        uint32_t    ts_usec;
        uint32_t    incl_len;
        uint32_t    orig_len;
    } pcaprec_hdr_t;

    uint64_t pos = 0;
    pcap_hdr_t* hdr = (pcap_hdr_t*)&bytes[pos];

    if (hdr->magic_number != 0xA1B2C3D4 &&
        hdr->magic_number != 0xA1B23C4D)
    {
        m_logger->LogError(this, "invalid PCAP header");
        return false;
    }

    pos += sizeof(pcap_hdr_t);

    while (pos < length)
    {
        printf("pos: %08zX", pos);

        pcaprec_hdr_t* rec = (pcaprec_hdr_t*)&bytes[pos];
        pos += sizeof(pcaprec_hdr_t);

        Packet* pkt = new Packet(
            rec->ts_sec,
            rec->ts_usec,
            rec->incl_len,
            &bytes[pos]);

        m_opaque->packets.push_back(pkt);

        pos += rec->incl_len;
    }

    return true;
}


uint8_t* Specimen::GetRawData()
{
    return m_opaque->bytes.data();
}


uint64_t Specimen::GetSize()
{
    return m_opaque->bytes.size();
}


unsigned int Specimen::GetPacketCount()
{
    return (unsigned int)m_opaque->packets.size();
}


bool Specimen::GetBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t*    buffer)
{
    uint64_t total_size = (uint64_t)m_opaque->bytes.size();

    if ((offset >= total_size) || ((offset + size) > total_size))
    {
        m_logger->LogWarning(this, "Specimen::GetBytes() out of range");
        return false;
    }

    memcpy(buffer, &m_opaque->bytes.data()[offset], size);

    return true;
}


bool Specimen::FillBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t     value)
{
    uint64_t stop = offset + size;
    for (uint64_t i = offset; i < stop; i++) m_opaque->bytes[i] = value;

    m_manager->Broadcast(BLADE_UPDATE_REPLACEMENT, offset, size, nullptr);

    return true;
}


bool Specimen::ReplaceBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t*    bytes)
{
    uint8_t* data = m_opaque->bytes.data();
    memcpy(&data[offset], bytes, size);

    m_manager->Broadcast(BLADE_UPDATE_REPLACEMENT, offset, size, nullptr);

    return true;
}


bool Specimen::InsertBytes(
    uint64_t    offset,
    uint64_t    size,
    uint8_t*    bytes)
{
    uint64_t old_size = (uint64_t)m_opaque->bytes.size();
    uint64_t tail_size = old_size - offset;

    old_size += size;
    m_opaque->bytes.resize(old_size);

    uint8_t* data = m_opaque->bytes.data();
    memmove(&data[offset + size], &data[offset], tail_size); // move tail chunk to the right
    memcpy(&data[offset], bytes, size); // insert new bytes
    
    m_manager->Broadcast(BLADE_UPDATE_INSERTION, offset, size, nullptr);

    return true;
}


bool Specimen::DeleteBytes(
    uint64_t    offset,
    uint64_t    size)
{
    uint64_t old_size = (uint64_t)m_opaque->bytes.size();

    vector<uint8_t> new_bytes;
    new_bytes.resize(old_size - size);

    uint8_t* data = m_opaque->bytes.data();
    uint8_t* new_data = new_bytes.data();

    uint64_t head_size = offset;
    uint64_t tail_size = old_size - (offset + size);

    memcpy(new_data, data, head_size);
    memcpy(&new_data[offset], &data[offset + size], tail_size);

    m_opaque->bytes.swap(new_bytes);

    m_manager->Broadcast(BLADE_UPDATE_DELETION, offset, size, nullptr);

    return true;
}


// REDIRECTOR
void Specimen::ClearSelection()
{
    if (m_app_component) { m_app_component->ClearSelection(); }
    else { ClearSelectionCore(); }
}


void Specimen::ClearSelectionCore()
{
    m_selection_exists = false;

    m_manager->Broadcast(BLADE_UPDATE_CLEAR_SELECTION, 0, 0, nullptr);
}


// REDIRECTOR
void Specimen::SetSelection(
    uint64_t    start_byte,
    uint8_t     start_bit,
    uint64_t    stop_byte,
    uint8_t     stop_bit)
{
    if (m_app_component)
    {
        m_app_component->SetSelection(
            start_byte, start_bit,
            stop_byte, stop_bit);
    }
    else
    {
        SetSelectionCore(
            start_byte, start_bit,
            stop_byte, stop_bit);
    }
}


// REDIRECTOR
void Specimen::SetSelection(
    unsigned int    packet,
    uint64_t        start_byte,
    uint8_t         start_bit,
    uint64_t        stop_byte,
    uint8_t         stop_bit)
{
    if (m_app_component)
    {
        m_app_component->SetSelection(
            start_byte, start_bit,
            stop_byte, stop_bit);
    }
    else
    {
        SetSelectionCore(
            start_byte, start_bit,
            stop_byte, stop_bit);
    }
}


void Specimen::SetSelectionCore(
    uint64_t    start_byte,
    uint8_t     start_bit,
    uint64_t    stop_byte,
    uint8_t     stop_bit)
{
    m_selection_exists = true;

    m_selection_start_byte = start_byte;
    m_selection_start_bit = start_bit;
    m_selection_stop_byte = stop_byte;
    m_selection_stop_bit = stop_bit;

    uint64_t start = (start_byte << 3) | (start_bit & 0x7);
    uint64_t stop = (stop_byte << 3) | (stop_bit & 0x7);

    m_manager->Broadcast(BLADE_UPDATE_SELECTION, start, stop, nullptr);
}


void Specimen::SetSelectionCore(
    unsigned int    packet,
    uint64_t        start_byte,
    uint8_t         start_bit,
    uint64_t        stop_byte,
    uint8_t         stop_bit)
{
    m_selection_exists = true;

    m_selection_packet = packet;
    m_selection_start_byte = start_byte;
    m_selection_start_bit = start_bit;
    m_selection_stop_byte = stop_byte;
    m_selection_stop_bit = stop_bit;

    uint64_t start = (start_byte << 3) | (start_bit & 0x7);
    uint64_t stop = (stop_byte << 3) | (stop_bit & 0x7);

    m_manager->Broadcast(BLADE_UPDATE_SELECTION, start, stop, (void*)((uint64_t)packet));
}