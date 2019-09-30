#ifndef AIRCRAFTCARRIER_CARRIER_H
#define AIRCRAFTCARRIER_CARRIER_H

#include "F16.h"
#include "F35.h"
#include <vector>
#include <iostream>
using std::vector;

class Carrier {

public:
    Carrier(int ammo, int hp);
    void add(Aircraft* aircraft);
    void fill();
    void fight(Carrier* enemyShip);
    void getStatus();
    int _healthPoint;

private:
    vector<Aircraft*> _aircrafts;
    int _ammo;

};


#endif //AIRCRAFTCARRIER_CARRIER_H
