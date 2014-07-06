#ifndef __STR_UTILS_H__
#define __STR_UTILS_H__

#include <string>

namespace str
{
/*
 *  \class Utils
 *  \brief Holds general utility functions for strings.
 */
struct Utils
{
    /*
     *  \func toUpper
     *  \brief Coverts a string to an all uppercase string.
     *
     *  \param input The string to convert. This will destroy
     *               the original string.
     */
    static void toUpper(std::string& input);

    /*
     *  \func toUpper
     *  \brief Coverts a string to an all uppercase string.
     *
     *  \param input The string to convert.
     *  \return The all uppercase string.
     */
    static inline std::string toUpper(const std::string& input)
    {
        std::string ret(input);
        toUpper(ret);
        return ret;
    }
};
}

#endif
