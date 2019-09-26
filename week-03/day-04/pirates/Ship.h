#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H
#include <vector>
#include "Pirate.h"


class Ship {

public:
    Ship(int maxCapacity);
    void fillShip();
    void getStatus();


    int _maxCapacity;
    vector<Pirate> _crew;
    Pirate _captain;
};


#endif //PIRATES_SHIP_H
