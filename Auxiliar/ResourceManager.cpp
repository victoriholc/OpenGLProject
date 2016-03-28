#include "ResourceManager.h"

TextureCache ResourceManager::m_textureCache;

GLTexture ResourceManager::getTexture(const char *filePath)
{
    return m_textureCache.getTexture(filePath);
}
