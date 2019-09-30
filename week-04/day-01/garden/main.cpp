#include <iostream>
#include "Garden.h"



int main() {

    Garden myGarden;
    Flower flower1("red");
    Flower flower2("blue");
    Tree tree1("apple");
    Tree tree2("peach");

    myGarden.addPlants(&flower1);
    myGarden.addPlants(&flower2);
    myGarden.addPlants(&tree1);
    myGarden.addPlants(&tree2);

    myGarden.info();
    myGarden.waterEmAll(40);

    myGarden.info();
    myGarden.waterEmAll(40);

    myGarden.info();


    return 0;
}