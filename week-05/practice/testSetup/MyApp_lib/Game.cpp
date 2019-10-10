#include "Game.h"

bool Game::isDifferent(int arr[4])
{
    for (int i = 0; i <  4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if(arr[i] == arr[j]) return false;  //false if not different
        }
    }
    return true;
}

Game::Game() : _status(gameState::playing), _guessses(0), _lastGuess(0)
{
    while(!isDifferent(_arr)) {
        for (int i = 0; i < 4; ++i) {
        _arr[i] = rand() % 10;
        }
    }
}


void Game::play()
{
    while (_status == gameState::playing){
        int cow = 0;
        int bull = 0;
        std::cout << "Guess a number!" << std::endl;
        std::cin >> _lastGuess;

        if (readInNUm()) {
            for (int i = 0; i < 4; i++) {
                bull += _guess[i] == _arr[3 - i];
                for (int j = 0; j < 4; j++){
                    cow += _guess[i] == _arr[j];
                }
            }
        } else std::cout << "Not a 4 digit number with different digits, try again!" << std::endl;
        cow -= bull;
        _guessses++;
        if (bull == 4) _status = gameState::finished;
        else std::cout << _lastGuess << " has " << bull << " bulls, and " << cow << " cows." << std::endl;
    }
    std::cout << "Congrats, you managed to complete the task in " << _guessses << " turns!" << std::endl;
}


bool Game::readInNUm()
{
    for (int i = 0; i < 4; i++){
        _guess[i] = 0;
    }
    for (int i = 0; i < 4; i++){
        _guess[i] = _lastGuess % 10;
        _lastGuess /= 10;
    }
    return ((_lastGuess == 0) && isDifferent(_guess));
}


int Game::getToGuess()
{
    return _arr[0] * 1000 + _arr[1] * 100 + _arr[2] * 10 + _arr[3];
}