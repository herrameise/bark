#include "Blade.h"
using namespace bark::app;



Blade::Blade(
    bark::core::Blade*  blade_core,
    LoggerBase*         logger,
    ManagerBase*        manager,
    SpecimenBase*       specimen) :
    m_blade_core(blade_core),
    m_logger(logger),
    m_manager(manager),
    m_specimen(specimen),
    m_ui(nullptr)
{
    blade_core->SetBladeApp(this);
}


// virtual function
void Blade::Update(
    bark::core::BLADE_UPDATE    update,
    uint64_t                    val1,
    uint64_t                    val2,
    void*                       ptr)
{
    m_blade_core->Update(update, val1, val2, ptr);
}