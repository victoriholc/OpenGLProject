#include "IOManager.h"
#include <fstream>
#include <iostream>

bool IOManager::readFileToBuffer(const char *filePath, std::vector<unsigned char> &buffer)
{
    std::fstream file(filePath, std::ios::in|std::ios::binary|std::ios::ate);
    if (file.fail())
    {
        perror(filePath);
        return false;
    }

    //Seek to the end of the file
    file.seekg(0, std::ios::end);
    //Get the file size
    //streamoff is a typdef of one the fundamental signed integral types large enough to represent the maximum possible file size supported by the system.
    std::streamoff fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    //Reduce the file size by any header bytes that might be present
    fileSize -= file.tellg();

    buffer.resize(fileSize);
    file.read((char *)&buffer[0], fileSize);
    file.close();

    return true;
}
