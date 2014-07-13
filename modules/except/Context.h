#ifndef __EXCEPT_CONTEXT_H__
#define __EXCEPT_CONTEXT_H__

#include <string>
#include <ostream>
#include <core/Types.h>

/*
 *  \macro CONTEXT
 *  \brief Convince function for creating Context objects for
 *         exception handling.
 *
 *  \param MESSAGE The message explaining the problem.
 *  \return A properly filled out Context object.
 */
#define CONTEXT(MESSAGE) nyra::except::Context(MESSAGE, \
                                               __FILE__, \
                                               __LINE__, \
                                               __func__, \
                                               __DATE__, \
                                               __TIME__)

namespace nyra
{
namespace except
{
/*
 *  \class Context
 *  \brief Hold information about an exception. Use the CONTEXT(MESSAGE)
 *         macro to create Context object easily.
 */
class Context
{
public:
    /*
     *  \func Constructor
     *  \brief Sets up an empty message. In general this should be avoided.
     *         As it does not give any meaningful information.
     */
    Context();

    /*
     *  \func Constructor
     *  \brief Copies a Context from another one.
     *
     *  \param other The Context to copy from.
     */
    Context(const Context& other);

    /*
     *  \func Constructor
     *  \brief Sets up a Context with only a single message.
     *
     *  \param message The message for the exception.
     */
    Context(const std::string& message);

    /*
     *  \func Constructor
     *  \brief Sets up a Context with full information. This is generally
     *         the best Context to create. Use the CONTEXT(MESSAGE) macro
     *         to quickly use this constructor with an exception.
     *
     *  \param message The message to display.
     *  \param file Recommended to be __FILE__
     *  \param line Recommended to be __LINE__
     *  \param function Recommended to be __func__
     *  \param date Recommended to be __DATE__
     *  \param time Recommended to be __TIME__
     */
    Context(const std::string& message,
            const std::string& file,
            core::uword line,
            const std::string& function,
            const std::string& date,
            const std::string& time);

    /*
     *  \func getFullMessage
     *  \brief Will get the fully formatted message based on the construction
     *         parameters.
     *
     *  \return The formatted string.
     */
    std::string getFullMessage() const;

private:
    std::string mMessage;
    std::string mFile;
    core::uword mLine;
    std::string mFunction;
    std::string mDate;
    std::string mTime;
    bool mExtended;
};

std::ostream& operator<<(std::ostream& os, const Context& context);

}
}
#endif
