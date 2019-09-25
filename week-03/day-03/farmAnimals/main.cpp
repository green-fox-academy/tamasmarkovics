#include <iostream>
#include "Animals.h"
#include "Farm.h"

/*
Create a Farm class
it has list of Animals
it has slots which defines the number of free places for animals
breed() -> creates a new animal if there's place for it
slaughter() -> removes the least hungry animal
 */

int main()
{
    Farm McDonaldsFarm(5);

    McDonaldsFarm.slaughter();
    McDonaldsFarm.breed();
    McDonaldsFarm.breed();
    McDonaldsFarm.breed();
    McDonaldsFarm.breed();
    McDonaldsFarm.breed();
    McDonaldsFarm.breed();
    McDonaldsFarm.slaughter();

    return 0;
}

//CAN I ADD DYNAMICALLY CHANGING NAMES INSIDE BREED FUNCTION?????????????????