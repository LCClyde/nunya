#ifndef __EXCEPT_EXCEPTION_H__
#define __EXCEPT_EXCEPTION_H__

#define LIB_EXCEPT
#include <addLibs.h>
#include <string>

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
     *  \brief Sets the internal structure of an exception. This is the most
     *         common constructor that should be used.
     *
     *  \param message A message that can be received which explains the error.
     */
    Exception(const std::string& message);

    /*
     *  \func Constructor
     *  \brief Copies an exsisting exception.
     *
     *  \param other The exception to copy.
     */
    Exception(const Exception& other);

    /*
     *  \func getMessage
     *  \brief Used to obtain information about what caused the exception.
     */
    inline std::string getMessage() const
    {
        return mMessage;
    }

private:
    Exception& operator=(const Exception&) { }

    const std::string mMessage;
};


}

#endif
