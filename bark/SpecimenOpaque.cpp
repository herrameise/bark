#include "SpecimenOpaque.h"
using namespace bark::core;

#include "Packet.h"



SpecimenOpaque::SpecimenOpaque() {}


SpecimenOpaque::~SpecimenOpaque()
{
    while (packets.empty() == false)
    {
        Packet* pkt = packets.back();
        delete pkt;
        packets.pop_back();
    }
}