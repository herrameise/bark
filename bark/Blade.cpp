#include "Blade.h"
using namespace bark::core;

#include "appstub/Blade.h"



Blade::Blade(
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen) :
    m_blade_app(nullptr),
    m_logger(logger),
    m_manager(manager),
    m_specimen(specimen) {}


Blade::~Blade() {}


void Blade::Update(
    BLADE_UPDATE    update,
    uint64_t        val1,
    uint64_t        val2,
    void*           ptr)
{
    if (m_blade_app) { m_blade_app->Update(update, val1, val2, ptr); }
    else { UpdateCore(update, val1, val2, ptr); }
}