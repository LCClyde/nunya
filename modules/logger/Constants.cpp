#include <logger/Constants.h>

namespace nyra
{
namespace logger
{
const core::uword Constants::LOG_CONSOLE = 0x01;
const core::uword Constants::LOG_FILE = 0x02;
const core::uword Constants::LOG_CONSOLE_FILE =
        Constants::LOG_CONSOLE | Constants::LOG_FILE;
}
}
