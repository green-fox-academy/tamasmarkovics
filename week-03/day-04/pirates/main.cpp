#include "Ship.h"
#include "Pirate.h"


int main()
{
    Ship flyingDutchman;
    flyingDutchman.fillShip();
    Ship pinkPearl;
    pinkPearl.fillShip();

    pinkPearl.getStatus();
    flyingDutchman.getStatus();

    flyingDutchman.battle(pinkPearl);

    pinkPearl.getStatus();
    flyingDutchman.getStatus();

    return 0;
}