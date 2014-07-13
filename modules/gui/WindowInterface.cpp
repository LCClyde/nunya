#include <gui/WindowInterface.h>

namespace nyra
{
namespace gui
{
WindowOptions::WindowOptions() :
    name("Default Window"),
    position(0, 0),
    size(852, 480)
{
}

WindowInterface::WindowInterface()
{
}

WindowInterface::~WindowInterface()
{
}

void WindowInterface::callEvent(core::uword id,
                                core::uword param1,
                                core::uword param2)
{
    EventList& eventList = mEventMap[id];
    for (EventList::iterator iter =  eventList.begin();
         iter != eventList.end();
         ++iter)
    {
        (*iter)->triggered(param1, param2);
    }
}

void WindowInterface::addEventHandler(core::uword id,
                                      EventHandler* handler)
{
    EventList& eventList = mEventMap[id];
    eventList.push_back(std::unique_ptr<EventHandler>(handler));
}
}
}
