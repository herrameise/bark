#include "ManagerOpaque.h"
using namespace bark::core;

#include "BladeEntry.h"



ManagerOpaque::ManagerOpaque() {}


ManagerOpaque::~ManagerOpaque()
{
    // blade deployments are cleared one-by-one
    // by the Manager directly instead of here

    while (entries.empty() == false)
    {
        BladeEntry* entry = entries.back();
        delete entry;
        entries.pop_back();
    }
}