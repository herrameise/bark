#ifndef __BARK_CORE___LOGGER_OPAQUE_H__
#define __BARK_CORE___LOGGER_OPAQUE_H__

#include <string>
using std::string;
#include <map>
using std::map;



namespace bark
{
    namespace core
    {
        class LoggerOpaque
        {
        public:
            LoggerOpaque() {}

            ~LoggerOpaque() {}

            map<void*, string> sources;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___LOGGER_OPAQUE_H__