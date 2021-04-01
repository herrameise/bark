#include "Manager.h"
#include "ManagerOpaque.h"
using namespace bark::core;

#include <string>
using std::string;

#ifdef _WIN32
#include <Windows.h>
#else // Linux/OSX
#include <dlfcn.h>
#endif // _WIN32

#include "appstub/ManagerBase.h"
#include "Logger.h"



Manager::Manager(
    Logger* logger) :
    m_app_component(nullptr),
    m_logger(logger),
    m_specimen(nullptr) // set later with SetSpecimen()
{
    m_opaque = new ManagerOpaque();
    m_logger->RegisterSource(this, "Manager [core]");
}


Manager::~Manager()
{
    delete m_opaque;
}


const char* Manager::GetBladesDirectory()
{
    return m_opaque->directory_string.c_str();
}


void Manager::SetBladesDirectory(
    const char* directory)
{
    m_opaque->directory = path(directory);
    m_opaque->directory_string = m_opaque->directory.string();
}


// REDIRECTOR
void Manager::RefreshEntries()
{
    if (m_app_component) { m_app_component->RefreshEntries(); }
    else { RefreshEntriesCore(); }
}


void Manager::RefreshEntriesCore()
{
    string message = "scanning directory \"" + m_opaque->directory.string() + "\" for blades";
    m_logger->LogInfo(this, message.c_str());

    if (is_directory(m_opaque->directory))
    {
        for (directory_entry& dirent : directory_iterator(m_opaque->directory))
        {
            path p = dirent.path();
            string ext = p.extension().string();
            string stem = p.stem().string();

#ifdef _WIN32
            if (ext == string(".dll"))
#else // Linux/OSX
            if (ext == string(".so"))
#endif // _WIN32
            {
                string mode = stem.substr(stem.size() - 4, 4);
                if (mode == string("Core"))
                {
                    string blade_name = stem.substr(0, stem.size() - string("Core").size());
                    LoadBlade(blade_name.c_str());
                }
            }
        }
    }
    else
    {
        string message = "\"" + m_opaque->directory.string() + "\" is not a directory";
        m_logger->LogError(this, message.c_str());
    }
}


// REDIRECTOR
bool Manager::LoadBlade(
    const char* name)
{
    if (m_app_component) { return m_app_component->LoadBlade(name); }
    else { return LoadBladeCore(name); }
}


bool Manager::LoadBladeCore(
    const char* name)
{
    // load "core" component shared object
#ifdef _WIN32
    string filename = m_opaque->directory.string() + string("\\") + string(name) + string("Core.dll");
    HMODULE handle = LoadLibraryA(filename.c_str());
    if (handle == NULL)
#else // Linux/OSX
    string filename = m_opaque->directory.string() + string("/") + string(name) + string("Core.so");
    void* handle = dlopen(filename.c_str(), RTLD_LAZY);
    if (handle == nullptr)
#endif // _WIN32
    {
        string message = "failed to load blade (core component): " + filename;
        m_logger->LogError(this, message.c_str());
        return false;
    }

    // import GetMetadata() function
#ifdef _WIN32
    GET_METADATA_CORE_FN GetMetadata = (GET_METADATA_CORE_FN)GetProcAddress(handle, "GetMetadata");
#else // Linux/OSX
    GET_METADATA_CORE_FN GetMetadata = (GET_METADATA_CORE_FN)dlsym(handle, "GetMetadata");
#endif // _WIN32
    if (GetMetadata == nullptr)
    {
        m_logger->LogError(this, "failed to resolve address of GetMetadata() in blade");
#ifdef _WIN32
        FreeLibrary(handle);
#else // Linux/OSX
        dlclose(handle);
#endif // _WIN32
        return false;
    }

    // get blade metadata
    BladeMetadata* metadata = GetMetadata();

    // import CreateBladeCore() function
#ifdef _WIN32
    CREATE_BLADE_CORE_FN CreateBladeCore = (CREATE_BLADE_CORE_FN)GetProcAddress(handle, "CreateBladeCore");
#else // Linux/OSX
    CREATE_BLADE_CORE_FN CreateBladeCore = (CREATE_BLADE_CORE_FN)dlsym(handle, "CreateBladeCore");
#endif // _WIN32
    if (CreateBladeCore == nullptr)
    {
        m_logger->LogError(this, "failed to import CreateBladeCore() from blade");
#ifdef _WIN32
        FreeLibrary(handle);
#else // Linux/OSX
        dlclose(handle);
#endif // _WIN32
        return false;
    }

    // import DestroyBladeCore() function
#ifdef _WIN32
    DESTROY_BLADE_CORE_FN DestroyBladeCore = (DESTROY_BLADE_CORE_FN)GetProcAddress(handle, "DestroyBladeCore");
#else // Linux/OSX
    DESTROY_BLADE_CORE_FN DestroyBladeCore = (DESTROY_BLADE_CORE_FN)dlsym(handle, "DestroyBladeCore");
#endif // _WIN32
    if (DestroyBladeCore == nullptr)
    {
        m_logger->LogError(this, "failed to import DestroyBladeCore() from blade");
#ifdef _WIN32
        FreeLibrary(handle);
#else // Linux/OSX
        dlclose(handle);
#endif // _WIN32
        return false;
    }

    // create entry in available blade list
    BladeEntry* entry = new BladeEntry;
    entry->metadata = metadata;
    entry->handle = handle;
    entry->CreateBladeCore = CreateBladeCore;
    entry->DestroyBladeCore = DestroyBladeCore;

    AddEntry(entry);

    // success!
    string message = "loaded blade: " + string(entry->metadata->name) + " (core component)";
    m_logger->LogDebug(this, message.c_str());
    return true;
}


void Manager::AddEntry(
    BladeEntry* entry)
{
    m_opaque->entries.push_back(entry);
}


BladeEntry* Manager::GetEntry(
    unsigned int index)
{
    if (index < GetEntryCount()) { return m_opaque->entries[index]; }
    else { return nullptr; }
}


BladeEntry* Manager::GetEntry(
    const char* name)
{
    for (unsigned int i = 0; i < m_opaque->entries.size(); i++)
    {
        BladeEntry* entry = m_opaque->entries[i];
        if (string(entry->metadata->name) == string(name)) return entry;
    }

    return nullptr;
}


unsigned int Manager::GetEntryCount()
{
    return (unsigned int)m_opaque->entries.size();
}


BladeDeployment* Manager::GetDeployment(
    unsigned int index)
{
    if (index < m_opaque->deployments.size()) { return m_opaque->deployments[index]; }
    else { return nullptr; }
}


BladeDeployment* Manager::GetDeployment(
    const char* name)
{
    for (unsigned int i = 0; i < m_opaque->deployments.size(); i++)
    {
        BladeDeployment* deployment = m_opaque->deployments[i];
        if (string(deployment->entry->metadata->name) == string(name)) return deployment;
    }

    return nullptr;
}


unsigned int Manager::GetDeploymentCount()
{
    return (unsigned int)m_opaque->deployments.size();
}


// REDIRECTOR
bool Manager::DeployBlade(
    BladeEntry* entry)
{
    if (m_app_component) { return m_app_component->DeployBlade(entry); }
    else { return DeployBladeCore(entry); }
}


bool Manager::DeployBladeCore(
    BladeEntry* entry)
{
    if (entry == nullptr) return false;

    CREATE_BLADE_CORE_FN CreateBladeCore = entry->CreateBladeCore;
    Blade* blade = CreateBladeCore(m_logger, this, m_specimen);
    if (blade == nullptr)
    {
        string message = string("failed to create blade: ") + string(entry->metadata->name);
        m_logger->LogError(this, message.c_str());
        return false;
    }

    BladeDeployment* deployment = new BladeDeployment;
    deployment->blade = blade;
    deployment->entry = entry;
    m_opaque->deployments.push_back(deployment);

    return true;
}


// REDIRECTOR
void Manager::CloseBlade(
    BladeDeployment* deployment)
{
    if (m_app_component) { m_app_component->CloseBlade(deployment); }
    else { CloseBladeCore(deployment); }
}


void Manager::CloseBladeCore(
    BladeDeployment* deployment)
{
    vector<BladeDeployment*> new_deployments;
    for (unsigned int i = 0; i < m_opaque->deployments.size(); i++)
    {
        BladeDeployment* test = m_opaque->deployments[i];
        if (test != deployment) new_deployments.push_back(test);
    }
    m_opaque->deployments.swap(new_deployments);

    deployment->entry->DestroyBladeCore(deployment->blade);
    delete deployment;
}


void Manager::CloseAllBlades()
{
    while (m_opaque->deployments.empty() == false)
    {
        CloseBlade(m_opaque->deployments.back());
    }
}


// REDIRECTOR
void Manager::Broadcast(
    BLADE_UPDATE    update,
    uint64_t        val1,
    uint64_t        val2,
    void*           ptr)
{
    if (m_app_component) { m_app_component->Broadcast(update, val1, val2, ptr); }
    else { BroadcastCore(update, val1, val2, ptr); }
}


void Manager::BroadcastCore(
    BLADE_UPDATE    update,
    uint64_t        val1,
    uint64_t        val2,
    void*           ptr)
{
#ifdef _DEBUG
    char* type;

    switch (update)
    {
    case BLADE_UPDATE_NEW:
        type = "NEW";
        break;
    case BLADE_UPDATE_SELECTION:
        type = "SELECTION";
        break;
    case BLADE_UPDATE_CLEAR_SELECTION:
        type = "CLEAR_SELECTION";
        break;
    case BLADE_UPDATE_REPLACEMENT:
        type = "REPLACEMENT";
        break;
    case BLADE_UPDATE_INSERTION:
        type = "INSERTION";
        break;
    case BLADE_UPDATE_DELETION:
        type = "DELETION";
        break;
    case BLADE_UPDATE_DEPLOYMENT:
        type = "DEPLOYMENT";
        break;
    case BLADE_UPDATE_CLOSURE:
        type = "CLOSURE";
        break;
    default:
        type = "(unknown)";
        break;
    }
    printf("Update: %s", type);
#endif // _DEBUG

    vector<BladeDeployment*>& deployments = m_opaque->deployments;

    for (uint32_t i = 0; i < deployments.size(); i++)
    {
        deployments[i]->blade->Update(update, val1, val2, ptr);
    }
}