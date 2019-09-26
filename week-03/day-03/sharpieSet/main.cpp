#include <iostream>
#include "Sharpie.h"
#include "SharpieSet.h"


int main() {
    Sharpie blue("blue", 4, 0);
    Sharpie green("blue", 4, 7);
    Sharpie yellow("blue", 4, 0);
    Sharpie black("blue", 4, 1);
    Sharpie orange("blue", 4, 2);
    Sharpie pink("blue", 4, 3);

    SharpieSet mySet;

    mySet.addSharpie(blue);
    mySet.addSharpie(green);
    mySet.addSharpie(yellow);
    mySet.addSharpie(black);
    mySet.addSharpie(orange);
    mySet.addSharpie(pink);

    std::cout << "I have " << mySet.countUsable() << " usable sharpies" << std::endl;
    mySet.getSharpie(3)->use();
    std::cout << "I have " << mySet.countUsable() << " usable sharpies" << std::endl;
    mySet.removeTrash();
    std::cout << black.getInkAmount() << std::endl;
    black.use();
    std::cout << black.getInkAmount() << std::endl;


    return 0;
}