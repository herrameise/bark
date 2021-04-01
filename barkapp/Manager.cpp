#include "Manager.h"
using namespace bark::app;

#include <string>
using std::string;
#include <iterator>
using std::back_inserter;
#include <vector>
using std::vector;
#ifdef _WIN32
#include <filesystem>
#else // Linux/OSX
#include <experimental/filesystem>
#include <dlfcn.h>
#endif // _WIN32
using namespace std::experimental::filesystem;

#include <wx/aui/framemanager.h>

#include <bark/appstub/Blade.h>
#include <bark/Bark.h>
#include <bark/Blade.h>
#include <bark/BladeEntry.h>
#include <bark/Manager.h>
#include "editor/Editor.h"
#include "editor/EditorCore.h"
#include "visualizer/Visualizer.h"
#include "visualizer/VisualizerCore.h"
#include "DeployBladeDialog.h"
#include "Logger.h"
#include "MainWindow.h"



Manager::Manager(
    bark::core::Manager*    manager_core,
    Logger*                 logger,
    MainWindow*             main_window,
    wxAuiManager*           aui_manager) :
    ManagerBase(manager_core, (bark::app::LoggerBase*)logger),
    m_main_window(main_window),
    m_aui_manager(aui_manager)
{
    m_logger->RegisterSource(this, "Manager [app]");
}


bool Manager::LoadBlade(
    const char* name)
{
    bool rv = m_manager_core->LoadBladeCore(name);
    if (rv == false) return false;

    // load "app" blade component shared object
#ifdef _WIN32
    string filename = string(GetBladesDirectory()) + string("\\") + string(name) + string("App.dll");
    HMODULE handle = LoadLibraryA(filename.c_str());
    if (handle == NULL)
#else // Linux/OSX
    string filename = string(GetBladesDirectory()) + string("/") + string(name) + string("App.so");
    void* handle = dlopen(filename.c_str(), RTLD_LAZY);
    if (handle == nullptr)
#endif // _WIN32
    {
        string message = "failed to load blade shared object (app component): " + filename;
        m_logger->LogError(this, message.c_str());
        return false;
    }

    // import CreateBladeApp() function
#ifdef _WIN32
    CREATE_BLADE_APP_FN CreateBladeApp = (CREATE_BLADE_APP_FN)GetProcAddress(handle, "CreateBladeApp");
#else // Linux/OSX
    CREATE_BLADE_APP_FN CreateBladeApp = (CREATE_BLADE_APP_FN)dlsym(handle, "CreateBladeApp");
#endif // _WIN32
    if (CreateBladeApp == nullptr)
    {
        m_logger->LogError(this, "failed to get address of CreateBladeApp() function");
#ifdef _WIN32
        FreeLibrary(handle);
#else // Linux/OSX
        dlclose(handle);
#endif // _WIN32
        return false;
    }

    // import DestroyBladeApp() function
#ifdef _WIN32
    DESTROY_BLADE_APP_FN DestroyBladeApp = (DESTROY_BLADE_APP_FN)GetProcAddress(handle, "DestroyBladeApp");
#else // Linux/OSX
    DESTROY_BLADE_APP_FN DestroyBladeApp = (DESTROY_BLADE_APP_FN)dlsym(handle, "DestroyBladeApp");
#endif // _WIN32
    if (DestroyBladeApp == nullptr)
    {
        m_logger->LogError(this, "failed to get address of DestroyBladeApp() function");
#ifdef _WIN32
        FreeLibrary(handle);
#else // Linux/OSX
        dlclose(handle);
#endif // _WIN32
        return false;
    }

    BladeEntry* blade_entry_app = new BladeEntry;
    blade_entry_app->CreateBladeApp = CreateBladeApp;
    blade_entry_app->DestroyBladeApp = DestroyBladeApp;

    bark::core::BladeEntry* blade_entry_core = m_manager_core->GetEntry(GetEntryCount() - 1);
    blade_entry_core->app_component = blade_entry_app;

    // success!
    string message = "loaded blade: " + string(blade_entry_core->metadata->name) + " (app component)";
    m_logger->LogDebug(this, message.c_str());
    return true;
}


bool Manager::DeployBlade(
    bark::core::BladeEntry* entry)
{
    bool rv = m_manager_core->DeployBladeCore(entry);
    if (rv == false) return false;

    if (entry->app_component == nullptr) return true;

    bark::core::BladeDeployment* deployment = GetDeployment(GetDeploymentCount() - 1);
    CREATE_BLADE_APP_FN CreateBladeApp = entry->app_component->CreateBladeApp;

    bark::core::Blade* blade_core = deployment->blade;
    Blade* blade_app = CreateBladeApp(blade_core, m_logger, this, m_specimen);
    if (blade_app == nullptr)
    {
        m_logger->LogError(this, "failed to create app component of blade");
        return false;
    }

    rv = blade_app->CreateUserInterface((void*)m_main_window);
    if (rv == false)
    {
        m_logger->LogWarning(this, "failed to create user interface for blade");
        return true;
    }

    wxWindow* panel = (wxWindow*)blade_app->GetUserInterface();
    m_aui_manager->AddPane(panel, wxCENTER, entry->metadata->name);
    wxAuiPaneInfo& pane = m_aui_manager->GetPane(panel);
    pane.Dockable(false);
    pane.Floatable(true);
    pane.CaptionVisible(true);
    pane.MaximizeButton(false);
    pane.MinimizeButton(false);
    pane.Float();
    m_aui_manager->Update();

    return true;
}


void Manager::CloseBlade(
    bark::core::BladeDeployment* deployment)
{
    BladeEntry* entry = deployment->entry->app_component;
    if (entry)
    {
        Blade* blade = deployment->blade->GetBladeApp();
        if (blade->GetUserInterface()) blade->DestroyUserInterface();
        entry->DestroyBladeApp(blade);
    }

    m_manager_core->CloseBladeCore(deployment);
}


void Manager::Broadcast(
    bark::core::BLADE_UPDATE    update,
    uint64_t                    val1,
    uint64_t                    val2,
    void*                       ptr)
{
    for (unsigned int i = 0; i < m_manager_core->GetDeploymentCount(); i++)
    {
        m_manager_core->GetDeployment(i)->blade->Update(update, val1, val2, ptr);
    }
}


void Manager::LoadInternalBlades()
{
    bark::core::BladeEntry* entry_core;
    BladeEntry* entry_app;

    // load "Editor"
    entry_core = new bark::core::BladeEntry;
    entry_core->metadata = bark::core::Editor_GetMetadata();
    entry_core->CreateBladeCore = bark::core::Editor_CreateBladeCore;
    entry_core->DestroyBladeCore = bark::core::Editor_DestroyBladeCore;

    entry_app = new BladeEntry;
    entry_app->CreateBladeApp = Editor_CreateBladeApp;
    entry_app->DestroyBladeApp = Editor_DestroyBladeApp;
    entry_core->app_component = entry_app;

    m_manager_core->AddEntry(entry_core);

    // load "Visualizer"
    entry_core = new bark::core::BladeEntry;
    entry_core->metadata = bark::core::Visualizer_GetMetadata();
    entry_core->CreateBladeCore = bark::core::Visualizer_CreateBladeCore;
    entry_core->DestroyBladeCore = bark::core::Visualizer_DestroyBladeCore;

    entry_app = new BladeEntry;
    entry_app->CreateBladeApp = Visualizer_CreateBladeApp;
    entry_app->DestroyBladeApp = Visualizer_DestroyBladeApp;
    entry_core->app_component = entry_app;

    m_manager_core->AddEntry(entry_core);
}


void Manager::LaunchDeployBladeDialog()
{
    DeployBladeDialog* dialog = new DeployBladeDialog(this);
    dialog->ShowModal();
}