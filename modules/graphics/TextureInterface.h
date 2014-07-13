#ifndef __GRAPHICS_TEXTURE_INTERFACE_H__
#define __GRAPHICS_TEXTURE_INTERFACE_H__

namespace nyra
{
namespace graphics
{
class TextureInterface
{
public:
    virtual ~TextureInterface() { }

protected:
    virtual void load(const std::string& pathname) = 0;
};
}
}

#endif
