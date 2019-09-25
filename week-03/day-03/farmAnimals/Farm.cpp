#include "Farm.h"
#include <iostream>

void Farm::breed()
{
    if(_slaughterHouse.size() < _maxCapacity){
        Animals canIEvenNameYouSomehowQuestionmark;
        _slaughterHouse.push_back(canIEvenNameYouSomehowQuestionmark);
    } else {
        std::cout << "The farm is dark, and full of animals" << std::endl;
    }
}
void Farm::slaughter()
{
    int toBeSlaughtered = 0;

    if (_slaughterHouse.size() != 0){
        for (int i = 1; i < _slaughterHouse.size(); i++){
            if (_slaughterHouse.size() != 0){
                if(_slaughterHouse[i].getHunger() > _slaughterHouse[toBeSlaughtered].getHunger()){
                    toBeSlaughtered = i;
                }
            } else {
                std::cout << "No more animals to eat!" << std::endl;
            }
        }
        _slaughterHouse.erase(_slaughterHouse.begin() + toBeSlaughtered);
        std::cout << "Animal at pen No." << toBeSlaughtered << " gave his blood for your hunger!\nI hope you are happy you evil freak." << std::endl;
        } else {
        std::cout << "No more animals to eat!";
    }
}


Farm::Farm(int maxCapacity)
{
    _maxCapacity = maxCapacity;
}