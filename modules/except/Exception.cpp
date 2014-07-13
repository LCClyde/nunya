#include <except/Exception.h>

namespace nyra
{
namespace except
{
Exception::Exception()
{
}

Exception::Exception(const std::string& message) :
    mContext(message)
{
}

Exception::Exception(const Exception& other) :
    mContext(other.mContext)
{
}

Exception::Exception(const Context& context) :
    mContext(context)
{
}

std::ostream& operator<<(std::ostream& os, const Exception& exception)
{
    os << exception.getFullMessage();
    return os;
}

}
}
