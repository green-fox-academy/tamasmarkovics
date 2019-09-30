#include "Tree.h"


Tree::Tree(string color)
{
    _color = color;
    _waterLevel = 0;
    _plantType = "tree";
}

void Tree::water(double amount)
{
    _waterLevel += amount * 0.4;
}

bool Tree::doesItNeedWater()
{
    return _waterLevel < 10;
}
