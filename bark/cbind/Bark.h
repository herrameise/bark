#ifndef __BARK_CORE_CBIND___BARK_H__
#define __BARK_CORE_CBIND___BARK_H__

#include "Export.h"



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    struct Bark
    {
        struct Logger*      logger;
        struct Manager*     manager;
        struct Specimen*    specimen;

        void* opaque;
    };

    BARK_CBIND_EXPORT struct Bark* Bark_Create();

    BARK_CBIND_EXPORT void Bark_Destroy(
        struct Bark* bark);

    BARK_CBIND_EXPORT BARK_ERROR_CODE Bark_Initialize(
        struct Bark* bark);

    BARK_CBIND_EXPORT struct Logger* Bark_GetLogger(
        struct Bark* bark);

    BARK_CBIND_EXPORT struct Manager* Bark_GetManager(
        struct Bark* bark);

    BARK_CBIND_EXPORT struct Specimen* Bark_GetSpecimen(
        struct Bark* bark);

    BARK_CBIND_EXPORT unsigned int Bark_GetVersionMajor(
        struct Bark* bark);

    BARK_CBIND_EXPORT unsigned int Bark_GetVersionMinor(
        struct Bark* bark);

    BARK_CBIND_EXPORT unsigned int Bark_GetVersionPatch(
        struct Bark* bark);

#ifdef __cplusplus
}
#endif // __cplusplus



#endif // __BARK_CORE_CBIND___BARK_H__