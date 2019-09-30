#ifndef GARDEN_GARDEN_H
#define GARDEN_GARDEN_H


#include "Flower.h"
#include "Tree.h"
#include <vector>
using std::vector;

class Garden {

public:
    void info();
    void waterEmAll(double amount);
    void addPlants(Plant*);

private:
    vector<Plant*> _myGarden;

};


#endif //GARDEN_GARDEN_H
