#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H

#include "StringedInstrument.h"


class BassGuitar : public StringedInstrument{
public:
    BassGuitar();
    void sound() override;

};


#endif //INSTRUMENTS_BASSGUITAR_H
