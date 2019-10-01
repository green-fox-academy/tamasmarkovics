#ifndef ZOO_ANIMALS_H
#define ZOO_ANIMALS_H

#include <string>
using std::string;

class Animals {
public:
    virtual string breed() = 0;
    virtual string getName() = 0;


protected:
    string _name;
};


#endif //ZOO_ANIMALS_H
