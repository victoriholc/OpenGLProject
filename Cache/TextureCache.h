#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include <map>
#include "GL/GLTexture.h"

class TextureCache
{
public:
    TextureCache();
    ~TextureCache();

    GLTexture getTexture(const char *filePath);

private:
    std::map<const char*, GLTexture> m_textureMap;
};

#endif // TEXTURECACHE_H
