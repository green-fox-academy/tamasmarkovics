#include <iostream>

#include "DiceSet.h"

int main(int argc, char* args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6
    DiceSet diceSet;
    int diceCounter = 0;
    for (int i = 0; i < 6; i++){
        while(diceSet.getCurrent(i) != 6){
            diceSet.roll(i);
            diceCounter++;
        }
    }
    for (int i = 0; i < 6; i++){
        std::cout << diceSet.getCurrent(i) << std::endl;
    }
    std::cout << diceCounter;


    return 0;
}