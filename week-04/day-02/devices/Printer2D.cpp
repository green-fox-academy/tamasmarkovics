#include "Printer2D.h"

Printer2D::Printer2D(int sizeX, int sizeY) : _sizeX(sizeX), _sizeY(sizeY) {}


string Printer2D::getSize()
{
    return std::to_string(_sizeX) + " X " + std::to_string(_sizeY);
}
