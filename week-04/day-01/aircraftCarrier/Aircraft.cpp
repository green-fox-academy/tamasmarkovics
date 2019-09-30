#include "Aircraft.h"
#include <iostream>


Aircraft::Aircraft()
{
    _currentAmmo = 0;
    _damageDealt = 0;
}

int Aircraft::fight()
{
    int dealtDamage = _currentAmmo * _damage;
    _currentAmmo = 0;
    _damageDealt += dealtDamage;
    return dealtDamage;
}


int Aircraft::refill(int fuel)
{
    if (fuel == 0){
        std::cout << "No more fuel!!" << std::endl;
        return 0;
    }
    int refillAmount = _maxAmmo - _currentAmmo;
    _currentAmmo = _maxAmmo;
    std::cout << fuel - refillAmount << " fuel remained." << std::endl;
    return fuel - refillAmount;
}

string Aircraft::getType()
{
    return (_type == Type::F16 ? "F16" : "F35");
}

void Aircraft::getStatus()
{
    std::cout << (_type == Type::F16 ? "F16" : "F35") << ", Ammo: " << _currentAmmo << ", Base Damage: " << _damage
    << ", All Damage: " << _damageDealt << std::endl;
}


bool Aircraft::isPrority()
{
    return _type == Type::F35;
}