#ifndef __GRAPHICS_SFML_TEXTURE_H__
#define __GRAPHICS_SFML_TEXTURE_H__

#include <string>
#include <SFML/Graphics.hpp>
#include <graphics/TextureInterface.h>

namespace nyra
{
namespace graphics
{
namespace sfml
{
class Texture : public TextureInterface
{
public:
    Texture(const std::string& pathname);

private:
    void load(const std::string& pathname);

    sf::Texture mTexture;
};
}
}
}
#endif
