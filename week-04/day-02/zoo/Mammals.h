#ifndef ZOO_MAMMALS_H
#define ZOO_MAMMALS_H


#include "LiveBearer.h"

class Mammals : public LiveBearer {

public:
    Mammals(string name);
    string getName() override;

};


#endif //ZOO_MAMMALS_H
