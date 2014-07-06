#include <str/Convert.h>

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
        throw except::Exception("Faled to covert string: " + s + " to bool");
}
}
