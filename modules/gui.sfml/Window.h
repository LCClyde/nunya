#ifndef __GUI_SFML_WINDOW_H__
#define __GUI_SFML_WINDOW_H__

#include <SFML/Window.hpp>
#include <gui/WindowInterface.h>

namespace nyra
{
namespace gui
{
namespace sfml
{
class Window : public WindowInterface
{
public:
    Window(const WindowOptions& options);

    void update();

    void close();

    void open();

    bool isOpen();

private:
    sf::Window mWindow;
};
}
}
}
#endif
