#include <iostream>
#include <logger/Logger.h>
#include <logger/Constants.h>
#include <except/Exception.h>

namespace nyra
{
namespace logger
{
Logger::Logger(core::uword flags,
               const std::string& outputPathname) :
    mFlags(flags)
{
    if (mFlags & Constants::LOG_FILE)
    {
        mFile.open(outputPathname.c_str());
        if (!mFile.is_open())
        {
            throw except::Exception(
                    CONTEXT("Failed to open file: " + outputPathname));
        }
    }
}

Logger::~Logger()
{
    if ((mFlags & Constants::LOG_FILE) && mFile.is_open())
    {
        mFile.close();
    }
}

void Logger::logMessage(const std::string& message)
{
    if (mFlags & Constants::LOG_CONSOLE)
        std::cout << message;
    if ((mFlags & Constants::LOG_FILE) && mFile.is_open())
        mFile << message;
}
}
}
