#ifndef __GRAPHICS_TRANSFORM_INTERFACE_H__
#define __GRAPHICS_TRANSFORM_INTERFACE_H__

#include <core/Types.h>
#include <core/Vector.h>

namespace nyra
{
namespace graphics
{
class TransformInterface
{
public:
    virtual ~TransformInterface() { }

    virtual inline core::Vector2<core::float_t> getPosition() const = 0;

    virtual inline core::float_t getRotation() const = 0;

    virtual inline core::Vector2<core::float_t> getScale() const = 0;

    virtual inline core::Vector2<core::float_t> getPivot() const = 0;

    virtual inline void setPosition(
            const core::Vector2<core::float_t>& position) = 0;

    inline void setPosition(core::float_t x, core::float_t y)
    {
        setPosition(core::Vector2<core::float_t>(x, y));
    }

    inline void setPosition(core::float_t xy)
    {
        setPosition(core::Vector2<core::float_t>(xy, xy));
    }

    inline void moveBy(const core::Vector2<core::float_t>& position)
    {
        setPosition(getPosition() + position);
    }

    inline void moveBy(core::float_t x, core::float_t y)
    {
        moveBy(core::Vector2<core::float_t>(x, y));
    }

    inline void moveBy(core::float_t xy)
    {
        moveBy(core::Vector2<core::float_t>(xy, xy));
    }

    virtual inline void setRotation(core::float_t degrees) = 0;

    inline void rotateBy(core::float_t degrees)
    {
        setRotation(getRotation() + degrees);
    }

    virtual inline void setScale(
            const core::Vector2<core::float_t>& scale) = 0;

    inline void setScale(core::float_t x, core::float_t y)
    {
        setScale(core::Vector2<core::float_t>(x, y));
    }

    inline void setScale(core::float_t xy)
    {
        setScale(core::Vector2<core::float_t>(xy, xy));
    }

    inline void scaleBy(const core::Vector2<core::float_t>& scale)
    {
        setScale(getScale() * scale);
    }

    inline void scaleBy(core::float_t x, core::float_t y)
    {
        scaleBy(core::Vector2<core::float_t>(x, y));
    }

    inline void scaleBy(core::float_t xy)
    {
        scaleBy(core::Vector2<core::float_t>(xy, xy));
    }

    virtual inline void setPivot(
            const core::Vector2<core::float_t>& pivot) = 0;

    inline void setPivot(core::float_t x, core::float_t y)
    {
        setPivot(core::Vector2<core::float_t>(x, y));
    }

    inline void setPivot(core::float_t xy)
    {
        setPivot(core::Vector2<core::float_t>(xy, xy));
    }
};
}
}

#endif
