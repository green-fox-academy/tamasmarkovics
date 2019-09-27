#include <iostream>
#include "Pirate.h"
#include <stdlib.h>
#include <time.h>


void Pirate::drinkSomeRum()
{
    if(_isUp()){
        _captainDrankThisMuch++;
        _drunkenness++;
        if (_drunkenness >= 4){
            passOut();
        }
    } else {
            std::cout << "He is dead. Or just passed out? I cant tell." << std::endl;
    }
}

Pirate::Pirate() :  _izDed (false), _isPassedOut (false), _drunkenness (0) {}

void Pirate::howItGoingMate()
{
    if(_isUp()) {
        if (_drunkenness = 0) {
            std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
        } else {
            for (int i = 0; i < 4; i++) {
                std::cout << "Pour me anudder!" << std::endl;
            }
        }
    } else {
        std::cout << "He is dead. Or just passed out? I cant tell." << std::endl;
    }
}

void Pirate::die()
{
    if(!_izDed){
        _izDed = true;
        std::cout << "RIP" << std::endl;
    } else {
        std::cout << "He ded already, stop it!!" << std::endl;
    }
}

void Pirate::brawl(Pirate &ahoy)
{
    srand (time(NULL));
    if (_isUp() && ahoy._isUp()){
        int whoDies = rand() % 3;
        switch  (whoDies){
            case 0:
                die();
                std::cout << "The attacker died!" << std::endl;
                break;
            case 1:
                ahoy.die();
                std::cout << "The defendant died!" << std::endl;
                break;
            case 2:
                passOut();
                ahoy.passOut();
                std::cout << "Both passed out, what losers!" << std::endl;
                break;
        }
    } else if(_izDed || ahoy._izDed) {
        std::cout << "Dead man tell no tales" << std::endl;
    } else {
            std::cout << "Too wasted to fight." << std::endl;
    }
}

void Pirate::passOut()
{
    _isPassedOut = true;
    std::cout << "Piss im out! *falls asleep*" << std::endl;
}

bool Pirate::_isUp()
{
    if (!_isPassedOut && !_izDed) {
        return true;
    } else return false;
}
