#include "Specimen.h"

#include "../Specimen.h"



int Specimen_Exists(
    struct Specimen* specimen)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    if (opaque->Exists() == true) return 1;
    else return 0;
}


SPECIMEN_MODE Specimen_GetMode(
    struct Specimen* specimen)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    
    switch (opaque->GetMode())
    {
    case bark::core::SPECIMEN_MODE_BLOB:
        return SPECIMEN_MODE_BLOB;
        break;

    case bark::core::SPECIMEN_MODE_PACKET:
        return SPECIMEN_MODE_PACKET;
        break;

    default:
        return SPECIMEN_MODE_BLOB;
        break;
    }
}


const char* Specimen_GetName(
    struct Specimen* specimen)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    return opaque->GetName();
}


void Specimen_SetName(
    struct Specimen*    specimen,
    const char*         name)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    opaque->SetName(name);
}


uint64_t Specimen_GetSize(
    struct Specimen* specimen)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    return opaque->GetSize();
}


void Specimen_Clear(
    struct Specimen* specimen)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    opaque->Clear();
}


BARK_ERROR_CODE Specimen_LoadFile(
    struct Specimen*    specimen,
    const char*         filename,
    SPECIMEN_MODE       mode)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    bool rv = opaque->LoadFile(filename, static_cast<bark::core::SPECIMEN_MODE>(mode));

    if (rv == true) return BARK_SUCCESS;
    else return BARK_FAILURE;
}


BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_FillBytes(
    struct Specimen*    specimen,
    uint64_t            offset,
    uint64_t            size,
    uint8_t             value)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    bool rv = opaque->FillBytes(offset, size, value);

    if (rv == true) return BARK_SUCCESS;
    else return BARK_FAILURE;
}


BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_ReplaceBytes(
    struct Specimen*    specimen,
    uint64_t            offset,
    uint64_t            size,
    uint8_t*            bytes)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    bool rv = opaque->ReplaceBytes(offset, size, bytes);

    if (rv == true) return BARK_SUCCESS;
    else return BARK_FAILURE;
}


BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_InsertBytes(
    struct Specimen*    specimen,
    uint64_t            offset,
    uint64_t            size,
    uint8_t*            bytes)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    bool rv = opaque->InsertBytes(offset, size, bytes);

    if (rv == true) return BARK_SUCCESS;
    else return BARK_FAILURE;
}


BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_DeleteBytes(
    struct Specimen*    specimen,
    uint64_t            offset,
    uint64_t            size)
{
    bark::core::Specimen* opaque = reinterpret_cast<bark::core::Specimen*>(specimen->opaque);
    bool rv = opaque->DeleteBytes(offset, size);

    if (rv == true) return BARK_SUCCESS;
    else return BARK_FAILURE;
}