#include "Packet.h"
using namespace bark::core;

#include <cstring>
using std::memcpy;



Packet::Packet(
    uint32_t            seconds,
    uint32_t            microseconds,
    unsigned int        length,
    uint8_t*            data)
{
    m_seconds = seconds;
    m_microseconds = microseconds;

    m_length = length;

    m_data = new uint8_t[length];
    memcpy(m_data, data, length);
}


Packet::~Packet()
{
    if (m_data) { delete[] m_data; }
}


void Packet::Clear()
{
    if (m_data) { delete[] m_data; }

    m_length = 0;
    m_data = nullptr;
}


void Packet::SetData(
    unsigned int    length,
    uint8_t*        data)
{
    if (m_data) { delete[] m_data; }

    m_length = length;
    memcpy(m_data, data, m_length);
}