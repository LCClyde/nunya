#include <str/Utils.h>
#include <algorithm>
#include <cctype>

namespace nyra
{
namespace str
{
void Utils::toUpper(std::string& input)
{
    std::transform(input.begin(),
                   input.end(),
                   input.begin(),
                   ::toupper);
}
}
}
