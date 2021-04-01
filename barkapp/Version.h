#ifndef __BARK_APP___VERSION_H__
#define __BARK_APP___VERSION_H__



#define BARK_APP_VERSION_MAJOR  0           //! Major version. Neither API nor ABI backward-compatible.
#define BARK_APP_VERSION_MINOR  1           //! Minor version. API backward-compatible, but not ABI backward-compatible.
#define BARK_APP_VERSION_PATCH  0           //! Both API and ABI backward-compatible.

#define BARK_APP_BUILD_DATE     __DATE__    //! Build date.
#define BARK_APP_BUILD_TIME		__TIME__    //! Build time of day.



#endif // __BARK_APP___VERSION_H__