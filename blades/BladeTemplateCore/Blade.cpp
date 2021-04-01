#include "Blade.h"
using namespace blade::blade_template::core;



BladeTemplate::BladeTemplate(
    Logger*     logger,
    Manager*    manager,
    Specimen*   specimen) :
    Blade(logger, manager, specimen) {}


BladeTemplate::~BladeTemplate() {}


void BladeTemplate::UpdateCore(
    BLADE_UPDATE    update,
    uint64_t        val1,
    uint64_t        val2,
    void*           ptr)
{
    switch (update)
    {
    case BLADE_UPDATE_NEW:
        break;

    case BLADE_UPDATE_SELECTION:
        break;

    case BLADE_UPDATE_CLEAR_SELECTION:
        break;

    case BLADE_UPDATE_REPLACEMENT:
        break;

    case BLADE_UPDATE_INSERTION:
        break;

    case BLADE_UPDATE_DELETION:
        break;

    case BLADE_UPDATE_DEPLOYMENT:
        break;

    case BLADE_UPDATE_CLOSURE:
        break;

    default:
        break;
    }
}