#ifndef __STR_CONVERT_H__
#define __STR_CONVERT_H__

#define LIB_STR
#include <addLibs.h>

#include <string>
#include <sstream>
#include <core/Types.h>
#include <except/Exception.h>

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
            throw except::Exception("Trying to covert an empty string.");

        T value;

        std::stringstream buffer(s);
        buffer.precision(str::Convert::getPrecision<T>(value));
        buffer >> value;

        if (buffer.fail())
            throw except::Exception("Failed to convert: " + s);

        return value;
    }

    /*
     *  \func toType
     *  \brief Used to convert a string to a bool type.
     *
     *  \param s The string you want to convert.
     *  \return The true or false value in the string.
     *  \throw Exception if the string cannot be converted to this data type.
     */
    template<> static core::bool_t toType<core::bool_t> (
            const std::string& s);

    /*
     *  \func toType
     *  \brief Used to convert a string to a string. Internally this does
     *         just returns the input. This is here for compiler reasons.
     *
     *  \param s The string you want to convert.
     *  \return The same string you passed in.
     */
    template<> static std::string toType<std::string> (const std::string& s)
    {
        return s;
    }

private:
    template<typename T> static core::uword getPrecision(const T&)
    {
        return 0;
    }

    template<> static core::uword getPrecision(const core::float_t&)
    {
        return std::numeric_limits<core::float_t>::digits10;
    }

    template<> static core::uword getPrecision(const core::double_t&)
    {
        return std::numeric_limits<core::double_t>::digits10;
    }

    template<> static core::uword getPrecision(const core::decimal_t&)
    {
        return std::numeric_limits<core::decimal_t>::digits10;
    }
};
}
#endif
