#ifndef PATHS
#define PATHS

#include <string>
#include <algorithm>

#ifdef _WIN32
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

extern const std::string &getProjectPath()
{
    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
        fatalError(strerror(errno));

    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

    std::string path(cCurrentPath);

    std::replace(path.begin(), path.end(), '\\', '/');
    path.erase(path.find_last_of('/'));
    return path;
}

#endif // PATHS

