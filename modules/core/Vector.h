#ifndef __CORE_VECTOR_H__
#define __CORE_VECTOR_H__

#include <ostream>
#include <core/Types.h>

namespace nyra
{
namespace core
{
template <typename T>
struct Vector2
{
    Vector2() :
        x(0),
        y(0)
    {
    }

    Vector2(const Vector2& other) :
        x(other.x),
        y(other.y)
    {
    }

    Vector2(const T& x, const T& y) :
        x(x),
        y(y)
    {
    }

    Vector2& operator=(const Vector2& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    bool operator==(const Vector2& rhs)
    {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const Vector2& rhs)
    {
        return !operator==(rhs);
    }

    Vector2& operator+=(const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2 operator+(const Vector2& rhs)
    {
        *this += rhs;
        return *this;
    }

    Vector2& operator-=(const Vector2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Vector2 operator-(const Vector2& rhs)
    {
        *this += rhs;
        return *this;
    }

    Vector2& operator*=(const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2 operator*(const Vector2& rhs)
    {
        *this += rhs;
        return *this;
    }

    Vector2& operator/=(const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2 operator/(const Vector2& rhs)
    {
        *this += rhs;
        return *this;
    }

    Vector2& operator+=(const T& rhs)
    {
        x += rhs;
        y += rhs;
        return *this;
    }

    Vector2 operator+(const T& rhs)
    {
        *this += rhs;
        return *this;
    }

    Vector2& operator-=(const T& rhs)
    {
        x -= rhs;
        y -= rhs;
        return *this;
    }

    Vector2 operator-(const T& rhs)
    {
        *this += rhs;
        return *this;
    }

    Vector2& operator*=(const T& rhs)
    {
        x += rhs;
        y += rhs;
        return *this;
    }

    Vector2 operator*(const T& rhs)
    {
        *this += rhs;
        return *this;
    }

    Vector2& operator/=(const T& rhs)
    {
        x += rhs;
        y += rhs;
        return *this;
    }

    Vector2 operator/(const T& rhs)
    {
        *this += rhs;
        return *this;
    }

    T x;
    T y;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& vector)
{
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}

}
}
#endif
