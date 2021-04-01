#ifndef __BARK_CORE___DEBUG_H__
#define __BARK_CORE___DEBUG_H__

#include "Export.h"

#include <cstdint>



namespace bark
{
    namespace core
    {
        void BARK_EXPORT PrintBytes(
            uint8_t*        bytes,
            unsigned int    size,
            unsigned int    bytes_per_line);

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___DEBUG_H__