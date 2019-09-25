#ifndef ANIMALSOOP_ANIMALS_H
#define ANIMALSOOP_ANIMALS_H


class Animals {
public:
    Animals();
    void eat();
    void drink();
    void play();
    int getHunger();
    int getThirst();

private:
    int _hunger;
    int _thirst;

};


#endif //ANIMALSOOP_ANIMALS_H

/*
Every animal has a hunger value, which is a whole number
Every animal has a thirst value, which is a whole number
when creating a new animal object these values are created with the default 50 value
Every animal can eat() which decreases their hunger by one
Every animal can drink() which decreases their thirst by one
Every animal can play() which increases both by one
*/
