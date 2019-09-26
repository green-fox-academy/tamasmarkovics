#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

class Pirate {

public:

    Pirate();
    void drinkSomeRum();
    void howItGoingMate();
    void die();
    void brawl(Pirate &ahoy);
    void passOut();
    bool _isUp();

    int _drunkenness;
    bool _isPassedOut;
    bool _izDed;
    int _captainDrankThisMuch;
};


#endif //PIRATES_PIRATE_H
