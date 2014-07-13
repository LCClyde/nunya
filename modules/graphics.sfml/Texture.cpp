#include <graphics.sfml/Texture.h>
#include <except/Exception.h>

namespace nyra
{
namespace graphics
{
namespace sfml
{
Texture::Texture(const std::string& pathname)
{
    load(pathname);
}

void Texture::load(const std::string& pathname)
{
    if (!mTexture.loadFromFile(pathname))
    {
        throw except::Exception(CONTEXT(
                "Failed to load texture: " + pathname));
    }
}
}
}
}
