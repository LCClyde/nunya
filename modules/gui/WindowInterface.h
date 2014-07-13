#ifndef __GUI_WINDOW_INTERFACE_H__
#define __GUI_WINDOW_INTERFACE_H__

#include <string>
#include <unordered_map>
#include <list>
#include <memory>
#include <core/Types.h>
#include <core/Vector.h>
#include <gui/EventHandler.h>

namespace nyra
{
namespace gui
{
/*
 *  \class WindowOptions
 *  \brief Options that can be passed into a Window constructor.
 *         This will default constructor to reasonable values that can be
 *         used as are.
 *
 *  \var name The name for the window. Some implementations may require
 *            this to be unique for the application.
 *  \var position The starting position of the window relative the top
 *                left corner of the primary monitor.
 *  \var size The size of the window in pixels. Defaults to 480p
 */
struct WindowOptions
{
    /*
     *  \func Constructor
     *  \brief Sets the window option to reasonable values.
     */
    WindowOptions();

    std::string name;
    core::Vector2<core::word> position;
    core::Vector2<core::word> size;
};

/*
 *  \class WindowInterface
 *  \brief Offers an abstract window object that all other windows should
 *         inherit from. This makes it very easy to change windows types in
 *         projects if necessary.
 */
class WindowInterface
{
public:
    /*
     *  \func Constructor
     *  \brief Default constructor for interface.
     */
    WindowInterface();

    /*
     *  \func Destructor
     *  \brief Here for inheritance.
     */
    virtual ~WindowInterface();

    /*
     *  \func update
     *  \brief This is where you should do your window updates and event
     *         handling.
     */
    virtual void update() = 0;

    /*
     *  \func close
     *  \brief Should close the window.
     */
    virtual void close() = 0;

    /*
     *  \func isOpen
     *  \brief Checks if a window is opened.
     *
     *  \return True if the window is opened
     */
    virtual bool isOpen() = 0;

    /*
     *  \func callEvent
     *  \brief Calls all the events mapped to an id.
     *
     *  \param id The event to trigger.
     *  \param param1 A custom value to send to the handlers.
     *  \param param2 A custom value to send to the handlers.
     */
    virtual void callEvent(core::uword id,
                           core::uword param1,
                           core::uword param2);

    /*
     *  \func addEventHandler
     *  \brief Sets an event handler to be called when the matching
     *         id occurs.
     *
     *  \param id The identifier that corresponds to the event. You can use
     *            the enum in EventHandler or custom ones depending on the
     *            Window you created.
     *  \param handler The handler to be added. The window will own this
     *                 memory. Do not manually delete it yourself.

     */
    virtual void addEventHandler(core::uword id,
                                 EventHandler* handler);

protected:
    typedef std::list<std::unique_ptr<EventHandler> > EventList;
    typedef std::unordered_map<core::uword, EventList> EventMap;
    EventMap mEventMap;
};
}
}
#endif
