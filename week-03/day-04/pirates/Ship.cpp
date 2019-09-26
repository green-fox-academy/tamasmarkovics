#include "Ship.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Pirate.h"

using std::vector;

Ship::Ship()
{
    srand (time(NULL));
    _maxCapacity = rand() % 10 + 10;
}

void Ship::fillShip()
{
    Pirate filler;
    for (int i = _isAlive(); i < _maxCapacity; i++){
        _crew.push_back(filler);
    }
    _captain =filler;
}

void Ship::getStatus() {
    std::cout << "The captain is ";
    if (_captain._drunkenness > 0){
        std::cout << "shitfaced!" << std::endl;
    } else {
        std::cout << "sober? Give him a drink!" << std::endl;
    }
    std::cout << "Our ship has " << _isAlive() << " sailors! The maximum we could ev is " << _maxCapacity << std::endl << std::endl;
}

int Ship::_isAlive() {
    int alive = 0;
    for (int i = 0; i < _maxCapacity; i++) {
        if (!_crew[i]._izDed) {
            alive++;
        }
    }
    return alive;
}

bool Ship::battle(Ship &otherShip)
{
    srand (time(NULL));
    if (_isAlive() - _captain._captainDrankThisMuch >= otherShip._isAlive() - otherShip._captain._captainDrankThisMuch){
        int losses = rand() % otherShip._isAlive();
        for (int i = 0; losses > 0; i++){
            if (!otherShip._crew[i]._izDed) {
                otherShip._crew[i].die();
                losses--;
            }
        }
        int drinks = rand() % 10;
        for (int i = 0; i < drinks; i++) {
            _captain.drinkSomeRum();
        }
        return true;

    } else {
        int losses = rand() % _isAlive();
        for (int i = 0; losses > 0; i++){
            if (!_crew[i]._izDed) {
                _crew[i].die();
                losses--;
            }
        }
        int drinks = rand() % 10 + 1;
        for (int i = 0; i < drinks; i++) {
            otherShip._captain.drinkSomeRum();
        }
        return false;

    }
}