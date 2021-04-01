#ifndef __BARK_CORE___MANAGER_OPAQUE_H__
#define __BARK_CORE___MANAGER_OPAQUE_H__

#include <string>
using std::string;
#include <vector>
using std::vector;

#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
using namespace boost::filesystem;



namespace bark
{
    namespace core
    {
        class BladeEntry;
        class BladeDeployment;

        class ManagerOpaque
        {
        public:
            ManagerOpaque();

            ~ManagerOpaque();

            path                        directory;
            string                      directory_string;
            vector<BladeEntry*>         entries;
            vector<BladeDeployment*>    deployments;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___MANAGER_OPAQUE_H__