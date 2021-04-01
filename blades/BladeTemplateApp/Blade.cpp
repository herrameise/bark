#include "Blade.h"
using namespace blade::blade_template::app;

#include "MainPanel.h"



BladeTemplate::BladeTemplate(
    blade::blade_template::core::BladeTemplate* blade_core,
    Logger*         logger,
    Manager*        manager,
    Specimen*       specimen) :
    Blade((bark::core::Blade*)blade_core, (LoggerBase*)logger, (ManagerBase*)manager, (SpecimenBase*)specimen) {}


BladeTemplate::~BladeTemplate() {}


bool BladeTemplate::CreateUserInterface(
    void* parent)
{
    MainPanel* main_panel = new MainPanel((wxWindow*)parent);
    if (main_panel == nullptr) return false;

    m_ui = (void*)main_panel;
    return true;
}


void BladeTemplate::DestroyUserInterface()
{
    MainPanel* main_panel = (MainPanel*)m_ui;
    main_panel->Destroy();
    m_ui = nullptr;
}


void BladeTemplate::Update(
    bark::core::BLADE_UPDATE    update,
    uint64_t                    val1,
    uint64_t                    val2,
    void*                       ptr)
{
    switch (update)
    {
    case bark::core::BLADE_UPDATE_NEW:
        break;

    case bark::core::BLADE_UPDATE_SELECTION:
        break;

    case bark::core::BLADE_UPDATE_CLEAR_SELECTION:
        break;

    case bark::core::BLADE_UPDATE_REPLACEMENT:
        break;

    case bark::core::BLADE_UPDATE_INSERTION:
        break;

    case bark::core::BLADE_UPDATE_DELETION:
        break;

    case bark::core::BLADE_UPDATE_DEPLOYMENT:
        break;

    case bark::core::BLADE_UPDATE_CLOSURE:
        break;

    default:
        break;
    }
}