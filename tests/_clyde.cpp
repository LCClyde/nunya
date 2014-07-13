#include <iostream>
#include <string>
#include <memory>
#include <except/Exception.h>
#include <gui.sfml/Window.h>
#include <gui.sfml/DefaultEventClose.h>

int main()
{
    try
    {
        nyra::gui::WindowOptions options;
        nyra::gui::sfml::Window window(options);
        window.addEventHandler(
                nyra::gui::EventHandler::CLOSED,
                new nyra::gui::sfml::DefaultEventClose(window));

        while (window.isOpen())
        {
            window.update();
        }
        return 0;
    }
    catch (nyra::except::Exception& ex)
    {
        std::cout << ex << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Caught unknown exception!" << std::endl;
    }
}
