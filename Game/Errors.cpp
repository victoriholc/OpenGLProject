#include "Errors.h"
#include <iostream>
#include <cstdlib>

void fatalError(const char *errorMessage)
{
    std::cout << errorMessage << std::endl;
    std::cout << "Enter any key to quit..." << std::endl;
    int key;
    std::cin >> key;
    exit(-1);
}
