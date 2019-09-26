#ifndef PIRATES_ARMADA_H
#define PIRATES_ARMADA_H
#include "Pirate.h"
#include "Ship.h"

int _sizeOfArmada = 10;

class Armada {

public:
    bool war(Armada &otherArmada);

    static int _sizeOfArmada;
    vector<Ship> miShippi;
};


#endif //PIRATES_ARMADA_H
