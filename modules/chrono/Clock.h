#ifndef __CHRONO_CLOCK_H__
#define __CHRONO_CLOCK_H__

#include <string>
#include <core/Types.h>
#include <str/Convert.h>

namespace chrono
{
/*
 *  \class Clock
 *  \brief Gets the local time of the users PC.
 */
class Clock
{
public:
    /*
     *  \func Constructor
     *  \brief Sets up the internal structure of the class. Internally
     *         this calls the update function.
     */
    Clock();

    /*
     *  \func update
     *  \brief Updates all the internal variables based on the current
     *         local time.
     */
    void update();

    /*
     *  \func getTime
     *  \brief Gets the current hours, minutes, and seconds.
     *
     *  \return String of the format HH:MM:SS.
     */
    inline std::string getTime() const
    {
        return getLeadingZeroNumber(mHour) + ":" +
                getLeadingZeroNumber(mMinute) + ":" +
                    getLeadingZeroNumber(mSecond);
    }

    /*
     *  \func getDate
     *  \breif Gets the current day, month, and year.
     *
     *  \return String of the format Jan 1, 2000.
     */
    inline std::string getDate() const
    {
        return mMonthString + " " + str::Convert::toString(mDay) +
                ", " + str::Convert::toString(mYear);
    }

    /*
     *  \func getSeconds
     *  \brief Gets the seconds position of the last updated time.
     */
    inline core::uword getSeconds() const
    {
        return mSecond;
    }

    /*
     *  \func getMinutes
     *  \brief Gets the mintues position of the last updated time.
     */
    inline core::uword getMinutes() const
    {
        return mMinute;
    }

    /*
     *  \func getHours
     *  \brief Gets the hours position of the last updated time.
     */
    inline core::uword getHours() const
    {
        return mHour;
    }

    /*
     *  \func getDays
     *  \brief Gets the days position of the last updated time.
     */
    inline core::uword getDays() const
    {
        return mDay;
    }

    /*
     *  \func getMonths
     *  \brief Gets the months position of the last updated time.
     */
    inline core::uword getMonths() const
    {
        return mMonth;
    }

    /*
     *  \func getYears
     *  \brief Gets the years position of the last updated time.
     */
    inline core::uword getYears() const
    {
        return mYear;
    }

    /*
     *  \func getMonthString
     *  \brief Gets the current month as a 3 letter string.
     */
    inline std::string getMonthString() const
    {
        return mMonthString;
    }

    /*
     *  \func getDayString
     *  \brief Gets the name of the current day.
     */
    inline std::string getDayString() const
    {
        return mDayString;
    }

private:
    std::string getLeadingZeroNumber(core::uword value) const;

    core::uword mSecond;
    core::uword mMinute;
    core::uword mHour;
    core::uword mDay;
    core::uword mMonth;
    core::uword mYear;
    std::string mMonthString;
    std::string mDayString;
};
}
#endif
