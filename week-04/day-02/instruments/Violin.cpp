#include "Violin.h"
#include <iostream>

Violin::Violin()
{
    _name = "Violin";
    _numberOfStrings = 4;
}
void Violin::sound()
{
    std::cout << "Screech" << std::endl;
}