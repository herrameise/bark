#ifndef __BARK_CORE___BLADE_METADATA_H__
#define __BARK_CORE___BLADE_METADATA_H__



namespace bark
{
    namespace core
    {
        class BladeMetadata
        {
        public:
            const char*     name;
            const char*     author;

            unsigned int    version_major;
            unsigned int    version_minor;
            unsigned int    version_patch;

            const char*     build_date;
            const char*     build_time;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___BLADE_METADATA_H__