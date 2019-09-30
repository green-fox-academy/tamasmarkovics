#include "Carrier.h"

Carrier::Carrier(int ammo, int hp)
{
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
    enemyShip->_healthPoint -= dmgDealt;

}

void getStatus()
{
    
}