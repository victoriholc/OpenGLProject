#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <vector>

class IOManager
{
public:
    static bool readFileToBuffer(const char *filePath, std::vector<char> &buffer);
};

#endif // IOMANAGER_H
