#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "GLTexture.h"

class ImageLoader
{
public:
    GLTexture loadPNG(const char *filePath);
};

#endif // IMAGELOADER_H
