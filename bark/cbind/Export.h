#ifndef __BARK_CORE_CBIND___EXPORT_H__
#define __BARK_CORE_CBIND___EXPORT_H__


#ifdef _WIN32
#define BARK_CBIND_EXPORT __declspec(dllexport)
#else // Linux/OSX
#define BARK_CBIND_EXPORT __attribute__((visibility("default")))
#endif // _WIN32

typedef enum BARK_ERROR_CODE
{
    BARK_SUCCESS = 0,
    BARK_FAILURE = 1
} BARK_ERROR_CODE;



#endif // __BARK_CORE_CBIND___EXPORT_H__