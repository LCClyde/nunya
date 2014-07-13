#ifndef __GRAPHICS_RENDERABLE_H__
#define __GRAPHICS_RENDERABLE_H__

#include <graphics/TransformInterface.h>

namespace nyra
{
namespace graphics
{
class Renderable
{
public:
    Renderable();

    Renderable(TransformInterface* transform);

    virtual ~Renderable() { }

    virtual void render() const = 0;

    inline TransformInterface* getTransform()
    {
        return mTransfrom.get();
    }

protected:
    std::auto_ptr<TransformInterface> mTransfrom;
};
}
}

#endif
