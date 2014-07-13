#ifndef __GUI_SFML_DEFAULT_EVENT_CLOSE_H__
#define __GUI_SFML_DEFAULT_EVENT_CLOSE_H__

#include <gui/EventHandler.h>
#include <gui/WindowInterface.h>

namespace nyra
{
namespace gui
{
namespace sfml
{
class DefaultEventClose : public EventHandler
{
public:
    DefaultEventClose(WindowInterface& window);

    void triggered(core::word param1,
                   core::word param2);

private:
    WindowInterface& mWindow;
};
}
}
}

#endif
