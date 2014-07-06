#include <str/Path.h>
#include <boost/filesystem.hpp>

namespace str
{
std::string Path::getBasename(const std::string& pathname)
{
    return boost::filesystem::basename(pathname);
}
}
