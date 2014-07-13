#include <sstream>
#include <except/Context.h>

namespace nyra
{
namespace except
{
Context::Context() :
    mMessage("No additional information is available."),
    mLine(0),
    mExtended(false)
{
}

Context::Context(const std::string& message) :
    mMessage(message),
    mLine(0),
    mExtended(false)
{
}

Context::Context(const Context& other) :
    mMessage(other.mMessage),
    mFile(other.mFile),
    mLine(other.mLine),
    mFunction(other.mFunction),
    mDate(other.mDate),
    mTime(other.mTime),
    mExtended(other.mExtended)
{
}

Context::Context(const std::string& message,
                 const std::string& file,
                 core::uword line,
                 const std::string& function,
                 const std::string& date,
                 const std::string& time) :
    mMessage(message),
    mFile(file),
    mLine(line),
    mFunction(function),
    mDate(date),
    mTime(time),
    mExtended(true)
{
}

std::string Context::getFullMessage() const
{
    // This purposely does not use str. Except should have no
    // dependencies.
    std::ostringstream buffer;
    buffer << mLine;

    std::string ret = "Message: " + mMessage;
    if (mExtended)
    {
        ret += "\nFile: " + mFile +
               "\nLine: " + buffer.str() +
               "\nFunction: " + mFunction +
               "\nDate: " + mDate +
               "\nTime: " + mTime;
     }
    return ret;
}


std::ostream& operator<<(std::ostream& os, const Context& context)
{
    os << context.getFullMessage();
    return os;
}
}
}
