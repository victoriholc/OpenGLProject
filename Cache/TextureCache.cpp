#include "TextureCache.h"
#include "Auxiliar/ImageLoader.h"
#include <stdio.h>

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
        m_textureMap.insert({filePath, newTexture});

        printf("Loaded texture...\n");

        return newTexture;
    }

    printf("Loaded cached texture...\n");
    return iterator->second;
}

