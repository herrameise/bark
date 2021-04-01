#ifndef __BARK_APP___EXPORT_H__
#define __BARK_APP___EXPORT_H__



#ifdef _WIN32
#define BARK_APP_EXPORT __declspec(dllexport)
#else // Linux/OSX
#define BARK_APP_EXPORT __attribute__((visibility("default")))
#endif // _WIN32



#endif // __BARK_APP___EXPORT_H__