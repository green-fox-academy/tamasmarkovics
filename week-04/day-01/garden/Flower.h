#ifndef GARDEN_FLOWER_H
#define GARDEN_FLOWER_H

#include "Plant.h"

class Flower : public Plant{

public:

    Flower(string color);
    void water(double amount) override;
    bool doesItNeedWater() override;

private:

};


#endif //GARDEN_FLOWER_H
