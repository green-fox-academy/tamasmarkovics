#include <iostream>
#include "Mammals.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Mammals monkey("monkey");

    std::cout << monkey.getName() << " is breeding by " << monkey.breed() << std::endl;
    return 0;
}