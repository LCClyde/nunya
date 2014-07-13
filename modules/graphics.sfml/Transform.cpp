#include <graphics.sfml/Transform.h>

namespace nyra
{
namespace graphics
{
namespace sfml
{
Transform::Transform(const sf::Transformable& tranformable) :
    TransformInterface(),
    mTransformable(tranformable)
{
}
}
}
}
