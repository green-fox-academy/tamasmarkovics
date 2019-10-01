#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H


#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument{

public:
    ElectricGuitar();
    void sound() override;

protected:

};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
