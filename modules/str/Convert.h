#ifndef __STR_CONVERT_H__
#define __STR_CONVERT_H__

#include <string>
#include <sstream>
#include <limits>
#include <core/Types.h>
#include <except/Exception.h>

namespace nyra
{
namespace str
{
/*
 *  \class Convert
 *  \brief Holds functions to covert strings to values and values to strings.
 */
struct Convert
{
    /*
     *  \func toString
     *  \brief Converts a value to a string.
     *
     *  \param value The value to turn into a string.
     *  \param precision The precision of the value, used for real numbers.
     *                   If you do not need custom precision, you should call
     *                   the version without this parameter.
     *  \return The string of the value.
     */
    template<typename T> static std::string toString(const T& value,
                                                     core::uword precision)
    {
        std::ostringstream buffer;
        buffer.precision(precision);
        buffer << std::boolalpha << value;
        return buffer.str();
    }

    /*
     *  \func toString
     *  \brief Converts a value to a string.
     *
     *  \param value The value to turn into a string.
     *  \return The string of the value.
     */
    template<typename T> static std::string toString(const T& value)
    {
        return str::Convert::toString<T>(
                value,
                str::Convert::getPrecision<T>(value));
    }

    /*
     *  \func toType
     *  \brief Converts a string to a value.
     *
     *  \param s The string you want to convert.
     *  \return The value the string contained.
     *  \throw Exception if the string is empty.
     *  \throw Exception if the string cannot be converted to this data type.
     */
    template<typename T> static T toType(const std::string& s)
    {
        if (s.empty())
            throw except::Exception(
                    CONTEXT("Trying to covert an empty string."));

        T value;

        std::stringstream buffer(s);
        buffer.precision(str::Convert::getPrecision<T>(value));
        buffer >> value;

        if (buffer.fail())
            throw except::Exception(
                    CONTEXT("Failed to convert: " + s));

        return value;
    }

private:
    template<typename T> static core::uword getPrecision(const T&)
    {
        return 0;
    }
};
}
}
#endif

