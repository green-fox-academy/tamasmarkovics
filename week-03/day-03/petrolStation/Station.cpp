#include <iostream>
#include "Station.h"

Station::Station()
{
    _gasAmount = 10000;
}


void Station::fill(Car &car)
{
    while (!car.isFull()){
        std::cout << "Filling the car!" << std::endl;
        _gasAmount--;
        car.fill();
    }
    std::cout << "Car filled up! Remaining gas: " << _gasAmount << std::endl;
}
