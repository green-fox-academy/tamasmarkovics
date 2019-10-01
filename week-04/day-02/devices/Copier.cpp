#include "Copier.h"



void Copier::copy()
{
    scan();
    print();
}

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed) {}
