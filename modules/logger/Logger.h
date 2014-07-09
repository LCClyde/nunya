#ifndef __LOGGER_LOGGER_H__
#define __LOGGER_LOGGER_H__

#include <string>
#include <fstream>
#include <core/Types.h>

namespace logger
{
/*
 *  \class Logger
 *  \brief Class to display messages to the user/developer.
 */
class Logger
{
public:
    enum
    {
        LOG_DEBUG,
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR
    };
    /*
     *  \func Constructor
     *  \brief Sets up the internal structure of the logger.
     *
     *  \param flags The type of logger.
     *  \param outputPathname The location of the save file for the logger.
     *  \throw Throws if it is unable to open a save file.
     */
    Logger(core::uword flags,
           const std::string& outputPathname);

    /*
     *  \func Destructor
     *  \brief Used to properly shutdown internal values of the logger.
     */
    ~Logger();

    /*
     *  \func logMessage
     *  \brief Outputs the message based on the flags used during construction.
     */
    void logMessage(const std::string& message);

private:
    const core::uword mFlags;
    std::ofstream mFile;
};
}
#endif
