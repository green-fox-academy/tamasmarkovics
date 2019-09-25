#ifndef SHARPIESET_SHARPIESET_H
#define SHARPIESET_SHARPIESET_H
#include "Sharpie.h"
#include <vector>

class SharpieSet {
public:
    int countUsable();
    void removeTrash();
    void addSharpie(Sharpie &sharpie);
private:
    std::vector<Sharpie> _listOfSharpies;
};


#endif //SHARPIESET_SHARPIESET_H
