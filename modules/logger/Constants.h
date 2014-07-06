#ifndef __LOGGER_CONSTANTS_H__
#define __LOGGER_CONSTANTS_H__

#include <core/Types.h>

namespace logger
{
/*
 *  \class Constants
 *  \brief Used to hold constants related to the logger.
 */
struct Constants
{
static const core::uword LOG_CONSOLE;
static const core::uword LOG_FILE;
static const core::uword LOG_CONSOLE_FILE;
};
}

#endif
