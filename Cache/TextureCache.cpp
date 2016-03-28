#include "TextureCache.h"
#include "Auxiliar/ImageLoader.h"

TextureCache::TextureCache()
{

}

TextureCache::~TextureCache()
{

}

GLTexture TextureCache::getTexture(const char *filePath)
{
    std::map<const char *, GLTexture>::iterator iterator = m_textureMap.find(filePath);
    //Checks if the textures is in the map
    if (iterator == m_textureMap.end())
    {
        GLTexture newTexture = ImageLoader::loadPNG(filePath);
        std::pair<const char*, GLTexture> newPair(filePath, newTexture);
        m_textureMap.insert({filePath, newTexture});

        return newTexture;
    }
    return iterator->second;
}

