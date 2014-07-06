#ifndef __LOGGER_LOG_H__
#define __LOGGER_LOG_H__

#define LIB_LOGGER
#include <addLibs.h>

#include <string>
#include <core/Types.h>
#include <logger/Logger.h>
#include <logger/Constants.h>

namespace logger
{
/*
 *  \func initialize
 *  \brief An optional function used to setup the type of logger.
 *         If this is not manually called it will be called during the
 *         first log call.
 *
 *  \param outputPathname The location of the save file of the log.
 *  \param flags The type of logs that will run.
 */
void initialize(const std::string& outputPathname = "./log.txt",
                core::uword flags = Constants::LOG_CONSOLE_FILE);

/*
 *  \func logInfo
 *  \brief Logs a simple message.
 *
 *  \param message The message to log.
 */
void logInfo(const std::string& message);

/*
 *  \func logWarning
 *  \brief Logs a simple message with the WARNING prefix.
 *
 *  \param message The message to log.
 */
void logWarning(const std::string& message);

/*
 *  \func logError
 *  \brief Logs a simple message with the ERROR prefix.
 *
 *  \param message The message to log.
 */
void logError(const std::string& message);
}

#endif
