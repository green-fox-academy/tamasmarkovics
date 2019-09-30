#ifndef GARDEN_TREE_H
#define GARDEN_TREE_H

#include "Plant.h"


class Tree : public Plant {

public:
    Tree(string color);

    void water(double amount) override;
    bool doesItNeedWater() override;

private:


};


#endif //GARDEN_TREE_H
