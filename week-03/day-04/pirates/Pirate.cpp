#include <iostream>
#include "Pirate.h"
#include <stdlib.h>
#include <time.h>
#include "Ship.h"


void Pirate::drinkSomeRum()
{
    if(!_izDed){
        _isDrunk = true;
    } else {
        std::cout << "He be ded!" << std::endl;
    }
}

Pirate::Pirate() : _isDrunk(false),
                   _izDed (false){}


void Pirate::howItGoingMate()
{
    if(!_izDed) {
        if (!_isDrunk) {
            std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
        } else {
            for (int i = 0; i < 4; i++) {
                std::cout << "Pour me anudder!" << std::endl;
            }
        }
    } else {
        std::cout << "He be ded!" << std::endl;
    }
}
void Pirate::die()
{
    if(!_izDed){
        _izDed = true;
    } else {
        std::cout << "He ded already, stop it!!" << std::endl;
    }
}

void Pirate::brawl(Pirate &ahoy)
{
    srand (time(NULL));
    if (!_izDed && !ahoy._izDed){
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
                die();
                ahoy.die();
                std::cout << "Both died, what losers!" << std::endl;
                break;
        }
    } else {
        std::cout << "Dead man tell no tales" << std::endl;
    }
}

