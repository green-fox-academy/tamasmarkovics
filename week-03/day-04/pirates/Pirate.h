#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

class Pirate {

public:

    Pirate();
    void drinkSomeRum();
    void howItGoingMate();
    void die();
    void brawl(Pirate &ahoy);


    bool _isDrunk;
    bool _izDed;
    int _captainDrankThisMuch;
};


#endif //PIRATES_PIRATE_H
