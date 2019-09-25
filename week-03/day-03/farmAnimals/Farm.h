#ifndef FARMANIMALS_FARM_H
#define FARMANIMALS_FARM_H
#include "Animals.h"
#include <vector>

class Farm {
public:
    Farm(int maxCapacity);
    void breed();
    void slaughter();
private:
    std::vector<Animals> _slaughterHouse;
    int _maxCapacity;
};


#endif //FARMANIMALS_FARM_H
