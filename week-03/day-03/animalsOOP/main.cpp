#include <iostream>
#include "Animals.h"

int main()
{
    Animals goat;
    goat.play();
    std::cout << "Hunger: " << goat.getHunger() << " thirst: " << goat.getThirst() << std::endl;
    goat.drink();
    goat.eat();
    std::cout << "Hunger: " << goat.getHunger() << " thirst: " << goat.getThirst() << std::endl;
    return 0;
}