#include <str/Convert.h>

namespace nyra
{
namespace str
{
template<> core::bool_t Convert::toType<core::bool_t> (const std::string& s)
{
    // TODO: Covert all character to lower case and check numeric values.
    if (s == "true")
        return true;
    else if (s == "false")
        return false;
    else
        throw except::Exception(
                CONTEXT("Failed to covert string: " + s + " to bool"));
}

template<> std::string Convert::toType<std::string> (const std::string& s)
{
    return s;
}

template<> core::uword Convert::getPrecision(const core::float_t&)
{
    return std::numeric_limits<core::float_t>::digits10;
}

template<> core::uword Convert::getPrecision(const core::double_t&)
{
    return std::numeric_limits<core::double_t>::digits10;
}

template<> core::uword Convert::getPrecision(const core::decimal_t&)
{
    return std::numeric_limits<core::decimal_t>::digits10;
}
}
}
