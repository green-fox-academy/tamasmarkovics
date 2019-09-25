#include "Car.h"

Car::Car(int capacity, int gasAmount)
{
    _capacity = capacity;
    _gasAmount = gasAmount;
}

bool Car::isFull()
{
    if (_capacity == _gasAmount) {
        return true;
    } else return false;
}
void Car::fill()
{
    if(_gasAmount < _capacity) {
        _gasAmount++;
    }
}


