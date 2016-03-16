#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "GL/GLTexture.h"

class ImageLoader
{
public:
    static GLTexture loadPNG(const char *filePath);
};

#endif // IMAGELOADER_H
