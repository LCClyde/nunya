#ifndef __STR_PATH_H__
#define __STR_PATH_H__

#include <string>

namespace nyra
{
namespace str
{
/*
 *  \class Path
 *  \brief Holds functions to deal with manipulating file paths.
 */
struct Path
{
    /*
     *  \func getBasename
     *  \brief Gets the name of the file without extension.
     *         Returns an empty string if a file does not exist.
     *         Example: C:/path1/path2/file.txt = file
     *
     *  \param pathname The pathname to take the file from.
     */
    static std::string getBasename(const std::string& pathname);
};
}
}
#endif
