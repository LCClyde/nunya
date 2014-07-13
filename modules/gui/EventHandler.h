#ifndef __GUI_EVENT_HANDLER_H__
#define __GUI_EVENT_HANDLER_H__

#include <core/Types.h>

namespace nyra
{
namespace gui
{
class EventHandler
{
public:
    enum
    {
        CLOSED,
        RESIZED,
        FOCUS_CHANGED,
        KEY_CHANGED,
        MOUSE_WHEEL,
        MOUSE_BUTTON_CHANGED,
        MOUSE_MOVED,
        MOUSE_ENTER_EXIT,
        CUSTOM
    };

    virtual ~EventHandler() { }

    virtual void triggered(core::word param1,
                           core::word param2) = 0;
};
}
}

#endif
