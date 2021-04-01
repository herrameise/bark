#ifndef __BARK_CORE___EXPORT_H__
#define __BARK_CORE___EXPORT_H__



#ifdef _WIN32
#define BARK_EXPORT __declspec(dllexport)
#else // Linux/OSX
#define BARK_EXPORT __attribute__((visibility("default")))
#endif // _WIN32



#endif // __BARK_CORE___EXPORT_H__