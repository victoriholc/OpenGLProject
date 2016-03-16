#define GLEW_STATIC
#include "ImageLoader.h"
#include "Auxiliar/PicoPNG.h"
#include "Auxiliar/IOManager.h"
#include "Auxiliar/Errors.h"
#include <string>
#include <stdio.h>

GLTexture ImageLoader::loadPNG(const char *filePath)
{
    GLTexture texture = {};

    printf("%s\n");

    std::vector<unsigned char> input;
    std::vector<unsigned char> output;
    unsigned long width, height;

    if (!IOManager::readFileToBuffer(filePath, input))
        fatalError("Failed to load PNG to buffer...");

    int errorCode = decodePNG(output, width, height, &input[0], input.size());
    if (errorCode != 0)
        fatalError(("Failed to decode PNG with error: " + std::to_string(errorCode)).c_str());

    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &output[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    texture.width = width;
    texture.height = height;
    return texture;
}
