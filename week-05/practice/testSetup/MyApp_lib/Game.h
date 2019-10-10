#ifndef MYAPP_GAME_H
#define MYAPP_GAME_H

#include <cstdlib>
#include <iostream>

enum class gameState {
    playing,
    finished
};

class Game {
public:
    bool isDifferent(int arr[4]);
    Game();
    void play();
    bool readInNUm();
    int getToGuess();

    int _arr[4] = {0, 0, 0, 0};
    gameState _status;
    int _guessses;
    int _lastGuess;
    int _guess[4];



};


#endif //MYAPP_GAME_H
