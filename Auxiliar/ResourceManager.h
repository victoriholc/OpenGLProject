#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Cache/TextureCache.h"

class ResourceManager
{
public:
    static GLTexture getTexture(const char *filePath);
private:
    static TextureCache m_textureCache;
};

#endif // RESOURCEMANAGER_H
