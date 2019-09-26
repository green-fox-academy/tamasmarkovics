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
};


#endif //PIRATES_PIRATE_H
