#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H
#include <iostream>
#include <string>
using std::string;

class Sharpie {
public:
    Sharpie(string color, float width, float inkAmount);
    string getColor();
    float getWidth();
    float getInkAmount();
    void use();
private:
    string _color;
    float _width;
    float _inkAmount;
};


#endif //SHARPIE_SHARPIE_H
