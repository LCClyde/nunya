#include <gui.sfml/DefaultEventClose.h>

namespace nyra
{
namespace gui
{
namespace sfml
{
DefaultEventClose::DefaultEventClose(WindowInterface& window) :
    mWindow(window)
{
}

void DefaultEventClose::triggered(core::word param1,
                                  core::word param2)
{
    mWindow.close();
}
}
}
}
