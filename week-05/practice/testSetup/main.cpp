#include <iostream>
#include <ctime>
#include "Game.h"

int main() {
    srand(time(nullptr));
    Game newGame;
    newGame.play();
    
    return 0;
}