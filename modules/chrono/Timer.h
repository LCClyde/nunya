#ifndef __CHRONO_TIMER_H__
#define __CHRONO_TIMER_H__

#include <chrono>
#include <core/Types.h>

namespace nyra
{
namespace chrono
{
/*
 *  \class Timer
 *  \brief Used to get the amount of time between frames.
 */
class Timer
{
public:
    Timer();

    core::double_t updateDeltaTime();

    inline core::double_t getDeltaTime()
    {
        return mDeltaTime.count();
    }

private:
    std::chrono::high_resolution_clock::time_point mLastTime;
    std::chrono::duration<core::double_t> mDeltaTime;
};
}
}
#endif
