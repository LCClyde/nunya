#include <graphics/Renderable.h>

namespace nyra
{
namespace graphics
{
Renderable::Renderable()
{
}

Renderable::Renderable(TransformInterface* transform) :
    mTransfrom(transform)
{
}

Renderable::~Renderable()
{
}
}
}
