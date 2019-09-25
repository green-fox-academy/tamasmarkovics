#include <iostream>
#include "Sharpie.h"

int main() {

    Sharpie blueSharpie("blue", 4);
    blueSharpie.use();
    std::cout << blueSharpie.getInkAmount();


    return 0;
}