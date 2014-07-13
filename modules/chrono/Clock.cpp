#include <chrono/Clock.h>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace nyra
{
namespace chrono
{
Clock::Clock()
{
    update();
}

void Clock::update()
{
    boost::posix_time::ptime now =
            boost::posix_time::second_clock::local_time();
    mYear = now.date().year();
    mMonth = now.date().month();
    mDay = now.date().day();
    mHour = now.time_of_day().hours();
    mMinute = now.time_of_day().minutes();
    mSecond = now.time_of_day().seconds();
    mDayString = now.date().day_of_week().as_long_string();
    mMonthString = now.date().month().as_long_string();
}

std::string Clock::getLeadingZeroNumber(core::uword value) const
{
    if (value == 0)
        return "00";
    else if (value < 10)
        return "0" + str::Convert::toString(value);
    return str::Convert::toString(value);
}
}
}
