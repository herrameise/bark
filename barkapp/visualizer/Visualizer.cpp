#include "Visualizer.h"
using namespace bark::app;

#include "../Specimen.h"
#include "VisualizerCore.h"
#include "VisualizerPanel.h"



Blade* bark::app::Visualizer_CreateBladeApp(
    bark::core::Blade*  blade_core,
    LoggerBase*         logger,
    ManagerBase*        manager,
    SpecimenBase*       specimen)
{
    Visualizer* editor = new Visualizer(
        (bark::core::VisualizerCore*)blade_core,
        (Logger*)logger,
        (Manager*)manager,
        (Specimen*)specimen);

    if (editor == nullptr) { return nullptr; }
    else { return (Blade*)editor; }
}


void bark::app::Visualizer_DestroyBladeApp(
    Blade* blade)
{
    Visualizer* editor = (Visualizer*)blade;
    delete editor;
}


Visualizer::Visualizer(
    bark::core::VisualizerCore*     visualizer_core,
    Logger*                         logger,
    Manager*                        manager,
    Specimen*                       specimen) :
    Blade((bark::core::Blade*)visualizer_core,
          (bark::app::LoggerBase*)logger,
          (bark::app::ManagerBase*)manager,
          (bark::app::SpecimenBase*)specimen) {}


void Visualizer::Update(
    bark::core::BLADE_UPDATE    update,
    uint64_t                    val1,
    uint64_t                    val2,
    void*                       ptr)
{
    if (m_ui)
    {
        VisualizerPanel* panel = (VisualizerPanel*)m_ui;

        switch (update)
        {
        case bark::core::BLADE_UPDATE_NEW:
            panel->Activate();
            panel->SyncWithSpecimen();
            panel->Resize();
            panel->GetBits();
            panel->Draw();
            break;

        case bark::core::BLADE_UPDATE_SELECTION:
            panel->SetSelection(
                (val1 >> 3) * 8 + (val1 & 0x7),
                (val2 >> 3) * 8 + (val2 & 0x7));
            panel->GetBits();
            panel->Draw();
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
}


bool Visualizer::CreateUserInterface(
    void* parent)
{
    if (m_ui) { return false; }

    VisualizerPanel* panel = new VisualizerPanel(
        (wxWindow*)parent,
        (bark::app::Logger*)m_logger,
        (bark::app::Manager*)m_manager,
        (bark::app::Specimen*)m_specimen);

    if (panel == nullptr) { return false; }

    m_ui = (void*)panel;
    return true;
}


void Visualizer::DestroyUserInterface()
{
    if (m_ui)
    {
        VisualizerPanel* panel = (VisualizerPanel*)m_ui;
        panel->Destroy();
        m_ui = nullptr;
    }
}