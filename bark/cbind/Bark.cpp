#include "Bark.h"
#include "Logger.h"
#include "Manager.h"
#include "Specimen.h"

#include "../Bark.h"

#include <cstddef>



struct Bark* Bark_Create(void)
{
    struct Bark* bark = new struct Bark;
    if (bark == nullptr) return NULL;

    bark->logger = nullptr;
    bark->manager = nullptr;
    bark->specimen = nullptr;

    bark->opaque = reinterpret_cast<void*>(new bark::core::Bark);
    if (bark->opaque == nullptr)
    {
        delete bark;
        return NULL;
    }

    return bark;
}


void Bark_Destroy(
    struct Bark* bark)
{
    delete reinterpret_cast<bark::core::Bark*>(bark->opaque);

    if (bark->logger) delete bark->logger;
    if (bark->manager) delete bark->manager;
    if (bark->specimen) delete bark->specimen;

    delete bark;
}


BARK_ERROR_CODE Bark_Initialize(
    struct Bark* bark)
{
    bark::core::Bark* opaque = reinterpret_cast<bark::core::Bark*>(bark->opaque);

    if (opaque->Initialize() == true)
    {
        bark->logger = new struct Logger;
        if (bark->logger == nullptr)
        {
            return BARK_FAILURE;
        }

        bark->manager = new struct Manager;
        if (bark->manager == nullptr)
        {
            delete bark->logger;
            return BARK_FAILURE;
        }

        bark->specimen = new struct Specimen;
        if (bark->specimen == nullptr)
        {
            delete bark->manager;
            delete bark->logger;
            return BARK_FAILURE;
        }

        bark->logger->opaque = opaque->GetLogger();
        bark->manager->opaque = opaque->GetManager();
        bark->specimen->opaque = opaque->GetSpecimen();

        return BARK_SUCCESS;
    }
    else
    {
        return BARK_FAILURE;
    }
}


struct Logger* Bark_GetLogger(
    struct Bark* bark)
{
    return bark->logger;
}


struct Manager* Bark_GetManager(
    struct Bark* bark)
{
    return bark->manager;
}


struct Specimen* Bark_GetSpecimen(
    struct Bark* bark)
{
    return bark->specimen;
}


unsigned int Bark_GetVersionMajor(
    struct Bark* bark)
{
    return ((bark::core::Bark*)(bark->opaque))->GetVersionMajor();
}


unsigned int Bark_GetVersionMinor(
    struct Bark* bark)
{
    return ((bark::core::Bark*)(bark->opaque))->GetVersionMinor();
}


unsigned int Bark_GetVersionPatch(
    struct Bark* bark)
{
    return ((bark::core::Bark*)(bark->opaque))->GetVersionPatch();
}