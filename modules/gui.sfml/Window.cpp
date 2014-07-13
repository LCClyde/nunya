#include <gui.sfml/Window.h>

namespace nyra
{
namespace gui
{
namespace sfml
{
Window::Window(const WindowOptions& options) :
        WindowInterface(),
        mWindow(sf::VideoMode(options.size.x, options.size.y),
                              options.name)
{
}

void Window::update()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            callEvent(EventHandler::CLOSED, 0, 0);
    }
}

void Window::close()
{
    mWindow.close();
}

bool Window::isOpen()
{
    return mWindow.isOpen();
}
}
}
}
