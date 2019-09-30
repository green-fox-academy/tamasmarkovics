#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H

#include <string>
using std::string;

enum class Type{
    F16,
    F35
};

class Aircraft {

public:
    Aircraft();
    int fight();
    int refill(int fuel);
    string getType();
    void getStatus();
    bool isPrority();

protected:
    int _maxAmmo;
    int _damage;
    int _currentAmmo;
    Type _type;
    int _damageDealt;
};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
