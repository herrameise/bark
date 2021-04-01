#ifndef __BARK_CORE_CBIND___SPECIMEN_H__
#define __BARK_CORE_CBIND___SPECIMEN_H__

#include <stdint.h>

#include "Export.h"



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    struct Specimen
    {
        void* opaque;
    };

    typedef enum SPECIMEN_ENCODING
    {
        SPECIMEN_ENCODING_PACKED = 0,
        SPECIMEN_ENCODING_UNPACKED = 1,
    } SPECIMEN_ENCODING;

    typedef enum SPECIMEN_MODE
    {
        SPECIMEN_MODE_BLOB = 0,
        SPECIMEN_MODE_PACKET = 1,
    } SPECIMEN_MODE;

    BARK_CBIND_EXPORT int Specimen_Exists(
        struct Specimen*    specimen);

    BARK_CBIND_EXPORT SPECIMEN_MODE Specimen_GetMode(
        struct Specimen*    specimen);

    BARK_CBIND_EXPORT const char* Specimen_GetName(
        struct Specimen*    specimen);

    BARK_CBIND_EXPORT void Specimen_SetName(
        struct Specimen*    specimen,
        const char*         name);

    BARK_CBIND_EXPORT uint64_t Specimen_GetSize(
        struct Specimen*    specimen);

    BARK_CBIND_EXPORT void Specimen_Clear(
        struct Specimen*    specimen);

    BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_LoadFile(
        struct Specimen*    specimen,
        const char*         filename,
        SPECIMEN_MODE       mode);

    BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_FillBytes(
        struct Specimen*    specimen,
        uint64_t            offset,
        uint64_t            size,
        uint8_t             value);

    BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_ReplaceBytes(
        struct Specimen*    specimen,
        uint64_t            offset,
        uint64_t            size,
        uint8_t*            bytes);

    BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_InsertBytes(
        struct Specimen*    specimen,
        uint64_t            offset,
        uint64_t            size,
        uint8_t*            bytes);

    BARK_CBIND_EXPORT BARK_ERROR_CODE Specimen_DeleteBytes(
        struct Specimen*    specimen,
        uint64_t            offset,
        uint64_t            size);


#ifdef __cplusplus
}
#endif // __cplusplus



#endif // __BARK_CORE_CBIND___SPECIMEN_H__