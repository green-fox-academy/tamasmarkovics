#include "BassGuitar.h"
#include <iostream>


BassGuitar::BassGuitar()
{
    _name = "Bass guitar";
    _numberOfStrings = 4;

}

void BassGuitar::sound()
{
    std::cout << "Duum-duum-duum" << std::endl;
}