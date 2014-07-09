#include <chrono/Timer.h>

namespace chrono
{
Timer::Timer() :
    mLastTime(std::chrono::high_resolution_clock::now()),
    mDeltaTime(mLastTime - mLastTime)
{
}

core::double_t Timer::updateDeltaTime()
{
    std::chrono::high_resolution_clock::time_point now =
            std::chrono::high_resolution_clock::now();
    mDeltaTime = now - mLastTime;
    mLastTime = now;
    return mDeltaTime.count();
}
}
