#include "Editor.h"
using namespace bark::app;

#include "../Specimen.h"
#include "EditorCore.h"
#include "EditorPanel.h"



Blade* bark::app::Editor_CreateBladeApp(
    bark::core::Blade*  blade_core,
    LoggerBase*         logger,
    ManagerBase*        manager,
    SpecimenBase*       specimen)
{
    Editor* editor = new Editor(
        (bark::core::EditorCore*)blade_core,
        (Logger*)logger,
        (Manager*)manager,
        (Specimen*)specimen);
    if (editor == nullptr) return nullptr;
    else return (Blade*)editor;
}


void bark::app::Editor_DestroyBladeApp(
    Blade* blade)
{
    Editor* editor = (Editor*)blade;
    delete editor;
}


Editor::Editor(
    bark::core::EditorCore*     editor_core,
    Logger*                     logger,
    Manager*                    manager,
    Specimen*                   specimen) :
    Blade((bark::core::Blade*)editor_core,
          (bark::app::LoggerBase*)logger,
          (bark::app::ManagerBase*)manager,
          (bark::app::SpecimenBase*)specimen) {}


void Editor::Update(
    bark::core::BLADE_UPDATE    update,
    uint64_t                    val1,
    uint64_t                    val2,
    void*                       ptr)
{
    if (m_ui)
    {
        EditorPanel* panel = (EditorPanel*)m_ui;

        uint64_t start_byte;
        uint8_t start_bit;
        uint64_t stop_byte;
        uint8_t stop_bit;

        switch (update)
        {
        case bark::core::BLADE_UPDATE_NEW:
            panel->SyncWithSpecimen();
            panel->ApplySettings();
            panel->AdjustSizes();
            panel->GenerateHeaders();
            panel->GenerateText();
            panel->FormatText();
            panel->Layout();
            break;

        case bark::core::BLADE_UPDATE_SELECTION:
            start_byte = val1 >> 3;
            start_bit = (uint8_t)(val1 & 0x7);
            stop_byte = val2 >> 3;
            stop_bit = (uint8_t)(val2 & 0x7);
            panel->SetSelection(start_byte, start_bit, stop_byte, stop_bit);
            panel->LocalizeSelectionRange();
            panel->FormatText();
            break;

        case bark::core::BLADE_UPDATE_CLEAR_SELECTION:
            panel->ClearSelection();
            break;

        case bark::core::BLADE_UPDATE_REPLACEMENT:
            panel->GenerateText();
            panel->FormatText();
            break;

        case bark::core::BLADE_UPDATE_INSERTION:
        case bark::core::BLADE_UPDATE_DELETION:
            panel->SyncWithSpecimen();
            panel->GenerateText();
            panel->FormatText();
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


bool Editor::CreateUserInterface(
    void* parent)
{
    if (m_ui) return false;

    EditorPanel* panel = new EditorPanel(
        (wxWindow*)parent,
        (bark::app::Logger*)m_logger,
        (bark::app::Manager*)m_manager,
        (bark::app::Specimen*)m_specimen);

    if (panel == nullptr) return false;

    if (m_specimen->SelectionExists())
    {
        panel->SetSelection(
            m_specimen->GetSelectionStartByte(),
            m_specimen->GetSelectionStartBit(),
            m_specimen->GetSelectionStopByte(),
            m_specimen->GetSelectionStopBit());
    }
    else
    {
        panel->ClearSelection();
    }

    panel->Layout();
    panel->SyncWithSpecimen();
    panel->ApplySettings();
    panel->AdjustSizes();
    panel->GenerateHeaders();
    panel->GenerateText();
    panel->FormatText();
    panel->Layout();

    m_ui = (void*)panel;
    return true;
}


void Editor::DestroyUserInterface()
{
    if (m_ui)
    {
        EditorPanel* panel = (EditorPanel*)m_ui;
        panel->Destroy();
        m_ui = nullptr;
    }
}