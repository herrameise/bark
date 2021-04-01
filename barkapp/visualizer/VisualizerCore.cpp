#include "VisualizerCore.h"
using namespace bark::core;

#include <wx/app.h>

#include <bark/Debug.h>
#include "../MainWindow.h"
#include "Visualizer.h"



static bark::core::BladeMetadata editor_metadata
{
    "Visualizer",
    "DZ Labs",
    0, 1, 0,
    __DATE__,
    __TIME__
};


bark::core::BladeMetadata* bark::core::Visualizer_GetMetadata()
{
    return &editor_metadata;
}


bark::core::Blade* bark::core::Visualizer_CreateBladeCore(
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen)
{
    VisualizerCore* editor_core = new VisualizerCore(logger, manager, specimen);
    
    if (editor_core == nullptr) return nullptr;
    else return (Blade*)editor_core;
}


void bark::core::Visualizer_DestroyBladeCore(
    Blade* blade)
{
    VisualizerCore* editor_core = (VisualizerCore*)blade;
    delete editor_core;
}


VisualizerCore::VisualizerCore(
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen) :
    Blade(logger, manager, specimen) {}


void VisualizerCore::UpdateCore(
    BLADE_UPDATE    update,
    uint64_t        val1,
    uint64_t        val2,
    void*           ptr) {}