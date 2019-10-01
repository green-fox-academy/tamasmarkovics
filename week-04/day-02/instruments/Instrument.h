#ifndef INSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTS_INSTRUMENT_H

#include <string>
using std::string;

class Instrument {

public:
    virtual void play() = 0;

protected:
    string _name;

};


#endif //INSTRUMENTS_INSTRUMENT_H
