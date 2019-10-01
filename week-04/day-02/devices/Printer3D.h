#ifndef DEVICES_PRINTER3D_H
#define DEVICES_PRINTER3D_H

#include "Printer.h"

class Printer3D : public Printer{

public:
    Printer3D(int sizeX, int sizeY, int sizeZ);

    string getSize() override;

protected:
    int _sizeX;
    int _sizeY;
    int _sizeZ;
};


#endif //DEVICES_PRINTER3D_H
