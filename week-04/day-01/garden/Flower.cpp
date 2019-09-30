#include <iostream>
#include "Flower.h"


Flower::Flower(string color)
{
    _color = color;
    _waterLevel = 0;
    _plantType = "flower";
}

void Flower::water(double amount)
{
    _waterLevel += amount * 0.75;
}

bool Flower::doesItNeedWater()
{
    return _waterLevel < 5;
}