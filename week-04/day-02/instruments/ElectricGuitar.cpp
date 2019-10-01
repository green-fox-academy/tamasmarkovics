#include "ElectricGuitar.h"
#include <iostream>


ElectricGuitar::ElectricGuitar()
{
    _name = "Electronic guitar";
    _numberOfStrings = 6;

}

void ElectricGuitar::sound()
{
    std::cout << "Twang" << std::endl;
}