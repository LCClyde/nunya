#ifndef __GRAPHICS_SFML_TRANSFORM_H__
#define __GRAPHICS_SFML_TRANSFORM_H__

#include <SFML/Graphics.hpp>
#include <core/Vector.h>
#include <graphics/TransformInterface.h>

namespace nyra
{
namespace graphics
{
namespace sfml
{
class Transform : public TransformInterface
{
public:
    Transform(const sf::Transformable& transformable);

    inline core::Vector2<core::float_t> getPosition()
    {
        sf::Vector2f position = mTransformable.getPosition();
        return core::Vector2<core::float_t>(position.x, position.y);
    }

    inline core::float_t getRotation()
    {
        return mTransformable.getRotation();
    }

    inline core::Vector2<core::float_t> getScale()
    {
        sf::Vector2f scale = mTransformable.getScale();
        return core::Vector2<core::float_t>(scale.x, scale.y);
    }

    inline core::Vector2<core::float_t> getPivot()
    {
        sf::Vector2f pivot = mTransformable.getOrigin();
        return core::Vector2<core::float_t>(pivot.x, pivot.y);
    }

    inline void setPosition(const core::Vector2<core::float_t>& position)
    {
        mTransformable.setPosition(position.x, position.y);
    }

    inline void setRotation(core::float_t degrees)
    {
        mTransformable.setRotation(degrees);
    }

    inline void setScale(const core::Vector2<core::float_t>& scale)
    {
        mTransformable.setScale(scale.x, scale.y);
    }

    inline void setPivot(const core::Vector2<core::float_t>& pivot)
    {
        mTransformable.setOrigin(pivot.x, pivot.y);
    }

private:
    sf::Transformable& mTransformable;
};
}
}
}

#endif
