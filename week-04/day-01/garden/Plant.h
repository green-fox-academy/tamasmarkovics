#ifndef GARDEN_PLANT_H
#define GARDEN_PLANT_H

#include <string>
using std::string;

class Plant {
public:
    virtual void water(float amount);
    virtual bool doesItNeedWater();
    virtual void status();

protected:
    float _waterLevel;
    string _plantType;
    string _color;
};


#endif //GARDEN_PLANT_H
