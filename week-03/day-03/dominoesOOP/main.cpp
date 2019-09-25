#include <iostream>
#include <vector>

#include "Domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...
    std::vector<Domino> dominoSnake;
    dominoSnake.push_back(dominoes[0]);
    for (int i = 1; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if(dominoSnake[i-1].getValues().second == dominoes[j].getValues().first){
                dominoSnake.push_back(dominoes[j]);
                j += 6;
            }
        }
    }

    for(int i = 0; i < dominoSnake.size(); i++){
        std::cout << dominoSnake[i].toString() << std::endl;
    }
    return 0;
}