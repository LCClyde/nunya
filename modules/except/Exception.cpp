#include <except/Exception.h>

namespace except
{
Exception::Exception() :
    mMessage("No additional information is available")
{
}

Exception::Exception(const std::string& message) :
    mMessage(message)
{
}

Exception::Exception(const Exception& other) :
    mMessage(other.mMessage)
{
}
}
