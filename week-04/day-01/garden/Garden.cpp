#include <iostream>
#include "Garden.h"


void Garden::info()
{
    for (int i = 0; i < _myGarden.size(); i++){
        _myGarden[i]->status();
    }
}

void Garden::waterEmAll(double amount)
{
    int needsWater = 0;
    for (int i = 0; i < _myGarden.size(); i++){
        if (_myGarden[i]->doesItNeedWater()){
            needsWater++;
        }
    }

    for (int i = 0; i < _myGarden.size(); i++){
        if (_myGarden[i]->doesItNeedWater()){
            _myGarden[i]->water(amount / needsWater);
        }
    }

    std::cout << std::endl <<"Watering " << needsWater << " plants with " << amount << " water." << std::endl << std::endl;
}

void Garden::addPlants(Plant* aPlantPointer)
{
    _myGarden.push_back(aPlantPointer);
}