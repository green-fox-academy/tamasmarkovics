#include "Animals.h"


Animals::Animals(){
    _hunger = 50;
    _thirst = 50;
}

void Animals::eat(){
    if (_hunger > 0){
        _hunger--;
    }
}
void Animals::drink(){
    if (_thirst > 0){
        _thirst--;
    }
}
void Animals::play(){
    _hunger++;
    _thirst++;
}

int Animals::getHunger() const {
    return _hunger;
}

int Animals::getThirst() const {
    return _thirst;
}
