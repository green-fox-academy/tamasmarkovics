#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include "Ship.h"

class Pirate {

public:

    Pirate();
    void drinkSomeRum();
    void howItGoingMate();
    void die();
    void brawl(Pirate &ahoy);
    bool _isDrunk;
    bool _izDed;
};


#endif //PIRATES_PIRATE_H
