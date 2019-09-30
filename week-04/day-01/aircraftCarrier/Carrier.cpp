#include "Carrier.h"

Carrier::Carrier(int ammo, int hp)
{
    _healthPoint = hp;
    _ammo = ammo;
}

void Carrier::add(Aircraft* aircraft)
{
    _aircrafts.push_back(aircraft);
}

void Carrier::fill()
{
    for (int i = 0; i < _aircrafts.size(); i++){
        if (_aircrafts[i]->isPrority()){
            _ammo = _aircrafts[i]->refill(_ammo);
        }
    }
    for (int i = 0; i < _aircrafts.size(); i++){
        if (!_aircrafts[i]->isPrority()){
            _ammo = _aircrafts[i]->refill(_ammo);
        }
    }
}

void Carrier::fight(Carrier* enemyShip)
{
    int dmgDealt = 0;
    for(int i = 0; i < _aircrafts.size(); i++){
        dmgDealt += _aircrafts[i]->fight();
    }

    if(enemyShip->_healthPoint -= dmgDealt <= 0){
        enemyShip->_healthPoint = 0;
        std::cout << "Ship sunk!" << std::endl;
    } else enemyShip->_healthPoint -= dmgDealt;

}

void Carrier::getStatus()
{
    std::cout << "Carrier ammo: " << _ammo << ", health point: " << _healthPoint << std::endl;
    for (int i = 0; i < _aircrafts.size(); i++){
        _aircrafts[i]->getStatus();
    }
}