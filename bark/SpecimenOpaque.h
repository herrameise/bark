#ifndef __BARK_CORE___SPECIMEN_OPAQUE_H__
#define __BARK_CORE___SPECIMEN_OPAQUE_H__

#include <string>
using std::string;
#include <vector>
using std::vector;



namespace bark
{
    namespace core
    {
        class Packet;

        class SpecimenOpaque
        {
        public:
            SpecimenOpaque();

            ~SpecimenOpaque();

            string              name;
            vector<uint8_t>     bytes;
            vector<Packet*>     packets;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___SPECIMEN_OPAQUE_H__