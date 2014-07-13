#include <memory>
#include <logger/Log.h>
#include <logger/Logger.h>
#include <except/Exception.h>
#include <chrono/Clock.h>

namespace
{
static std::unique_ptr<nyra::logger::Logger> loggerInstance;
}

namespace nyra
{
namespace logger
{
void initialize(const std::string& outputPathname,
                core::uword flags)
{
    if (loggerInstance.get())
        throw except::Exception(
                CONTEXT("The global logger is being recreated."));
    loggerInstance.reset(new logger::Logger(flags, outputPathname));
}

void logInfo(const std::string& message)
{
    if (!loggerInstance.get())
        logger::initialize();

    chrono::Clock clock;
    std::string newMessage = clock.getTime() + ": " + message + "\n";
    loggerInstance->logMessage(newMessage);
}

void logWarning(const std::string& message)
{
    logger::logInfo("WARNING: " + message);
}

void logError(const std::string& message)
{
    logger::logInfo("ERROR: " + message);
}
}
}
