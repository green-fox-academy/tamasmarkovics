#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H
#include <vector>
#include "Pirate.h"

using std::vector;

class Ship {

public:

    Ship();
    void fillShip();
    void getStatus();
    int _isAlive();
    bool battle(Ship &otherShip);


    int _maxCapacity;
    vector<Pirate> _crew;
    Pirate _captain;
};


#endif //PIRATES_SHIP_H
