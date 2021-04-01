#include "ManagerBase.h"
using namespace bark::app;

#include "../BladeEntry.h"



ManagerBase::ManagerBase(
    bark::core::Manager*    manager_core,
    LoggerBase*             logger) :
    m_manager_core(manager_core),
    m_logger(logger)
{
    m_manager_core->SetAppComponent(this);
}


const char* ManagerBase::GetBladesDirectory()
{
    return m_manager_core->GetBladesDirectory();
}


void ManagerBase::SetBladesDirectory(
    const char* directory)
{
    m_manager_core->SetBladesDirectory(directory);
}


// virtual function
void ManagerBase::RefreshEntries()
{
    m_manager_core->RefreshEntriesCore();
}


// virtual function
bool ManagerBase::LoadBlade(
    const char* name)
{
    return m_manager_core->LoadBladeCore(name);
}


void ManagerBase::AddEntry(
    bark::core::BladeEntry* entry)
{
    m_manager_core->AddEntry(entry);
}


bark::core::BladeEntry* ManagerBase::GetEntry(
    unsigned int index)
{
    return m_manager_core->GetEntry(index);
}


bark::core::BladeEntry* ManagerBase::GetEntry(
    const char* name)
{
    return m_manager_core->GetEntry(name);
}


unsigned int ManagerBase::GetEntryCount()
{
    return m_manager_core->GetEntryCount();
}


bark::core::BladeDeployment* ManagerBase::GetDeployment(
    unsigned int index)
{
    return m_manager_core->GetDeployment(index);
}


bark::core::BladeDeployment* ManagerBase::GetDeployment(
    const char* name)
{
    return m_manager_core->GetDeployment(name);
}


unsigned int ManagerBase::GetDeploymentCount()
{
    return m_manager_core->GetDeploymentCount();
}


// virtual function
bool ManagerBase::DeployBlade(
    bark::core::BladeEntry* entry)
{
    return m_manager_core->DeployBladeCore(entry);
}


// virtual function
void ManagerBase::CloseBlade(
    bark::core::BladeDeployment* deployment)
{
    m_manager_core->CloseBladeCore(deployment);
}


void ManagerBase::CloseAllBlades()
{
    m_manager_core->CloseAllBlades();
}


// virtual void
void ManagerBase::Broadcast(
    bark::core::BLADE_UPDATE    update,
    uint64_t                    val1,
    uint64_t                    val2,
    void*                       ptr)
{
    m_manager_core->Broadcast(update, val1, val2, ptr);
}