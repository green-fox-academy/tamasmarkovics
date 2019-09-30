#ifndef GARDEN_PLANT_H
#define GARDEN_PLANT_H

#include <string>
using std::string;

class Plant {

public:
    virtual void water(double amount);
    virtual bool doesItNeedWater();
    virtual void status();

protected:
    double _waterLevel;
    string _plantType;
    string _color;

};


#endif //GARDEN_PLANT_H
