#include <iostream>
#include "Plant.h"



void Plant::water(double amount)
{
    _waterLevel += amount * 1;
}

bool Plant::doesItNeedWater()
{
    return _waterLevel < 10;
}

void Plant::status()
{
    std::cout << "The " << _color << " " << _plantType;
    if(doesItNeedWater()){
        std::cout << " needs water." << std::endl;
    } else {
        std::cout << " doesnt need water." << std::endl;
    }
}

