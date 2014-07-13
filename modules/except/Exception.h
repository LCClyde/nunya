#ifndef __EXCEPT_EXCEPTION_H__
#define __EXCEPT_EXCEPTION_H__

#include <string>
#include <ostream>
#include <except/Context.h>

#define Ctxt

namespace nyra
{
namespace except
{
/*
 *  \class Exception
 *  \brief Used to throw and catch exceptions.
 */
class Exception
{
public:
    /*
     *  \func Constructor
     *  \brief Sets up a default exception. The default constructor should
     *         be avoid in favor of a more meaningful option.
     */
    Exception();

    /*
     *  \func Constructor
     *  \brief Sets the internal structure of an exception.
     *
     *  \param message A message that can be received which explains the error.
     */
    Exception(const std::string& message);

    /*
     *  \func Constructor
     *  \brief Copies an existing exception.
     *
     *  \param other The exception to copy.
     */
    Exception(const Exception& other);

    /*
     *  \func Constructor
     *  \brief Creates an Exception from a context. This is the most common
     *         constructor that should be used.
     *
     *  \param context The context for the exception.
     */
    Exception(const Context& context);

    /*
     *  \func getFullMessage
     *  \brief Gets the formatted message from the context.
     *
     *  \return The formatted message.
     */
    inline std::string getFullMessage() const
    {
        return mContext.getFullMessage();
    }

private:
    const Context mContext;
};

std::ostream& operator<<(std::ostream& os, const Exception& exception);

}
}
#endif
