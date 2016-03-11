#include "IOManager.h"
#include <fstream>

bool IOManager::readFileToBuffer(const char *filePath, std::vector<char> &buffer)
{
    std::fstream file(filePath, std::ios::binary);
    if (file.fail())
    {
        perror(filePath);
        return false;
    }

    //Seek to the end of the file
    file.seekg(0, std::ios::end);
    //Get the file size
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    //Reduce the file size by any header bytes that might be present
    fileSize -= file.tellg();

    buffer.resize(fileSize);
    file.read(&buffer[0], fileSize);
    file.close();

    return true;
}
