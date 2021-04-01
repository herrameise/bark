#include "BladeEntry.h"
using namespace bark::core;

#include "appstub/BladeEntry.h"



BladeEntry::BladeEntry() :
    app_component(nullptr)
{
#ifdef _WIN32
    handle = NULL;
#else // Linux/OSX
    handle = nullptr;
#endif // _WIN32
}


BladeEntry::~BladeEntry()
{
    if (app_component) { delete app_component; }
}