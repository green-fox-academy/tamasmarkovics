#include "Ship.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

using std::vector;

Ship::Ship(int maxCapacity)
{
    srand (time(NULL));
    _maxCapacity = rand() % 10 + 10;
}


void Ship::fillShip()
{
    Pirate Joe;
    for (int i = 0; i < _maxCapacity; i++){
        _crew.push_back(Joe);
    }
    _captain = Joe;
}

void Ship::getStatus() {
    std::cout << "The captain is ";
    if (_captain._isDrunk){
        std::cout << "shitfaced!" << std::endl;
    } else {
        std::cout << "sober? Give him a drink" << std::endl;
    }
    int alive = 0;
    for (int i = 0; i < _maxCapacity; i++){
        if (!_crew[i]._izDed){
            alive++;
        }
    }
    std::cout << "Our ship has " << alive << " sailors! The maximum we could ev is " << _maxCapacity << std::endl;
}
