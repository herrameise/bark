#include "EditorCore.h"
using namespace bark::core;

#include <wx/app.h>

#include <bark/Debug.h>
#include "../MainWindow.h"
#include "Editor.h"



static bark::core::BladeMetadata editor_metadata
{
    "Editor",
    "DZ Labs",
    0, 1, 0,
    __DATE__,
    __TIME__
};


bark::core::BladeMetadata* bark::core::Editor_GetMetadata()
{
    return &editor_metadata;
}


bark::core::Blade* bark::core::Editor_CreateBladeCore(
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen)
{
    EditorCore* editor_core = new EditorCore(logger, manager, specimen);
    
    if (editor_core == nullptr) return nullptr;
    else return (Blade*)editor_core;
}


void bark::core::Editor_DestroyBladeCore(
    Blade* blade)
{
    EditorCore* editor_core = (EditorCore*)blade;
    delete editor_core;
}


EditorCore::EditorCore(
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen) :
    Blade(logger, manager, specimen) {}


void EditorCore::UpdateCore(
    BLADE_UPDATE    update,
    uint64_t        val1,
    uint64_t        val2,
    void*           ptr) {}