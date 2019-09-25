#include "Sharpie.h"
#include "SharpieSet.h"


Sharpie::Sharpie(string color, float width, float inkAmount){
    _color = color;
    _width = width;
    _inkAmount = inkAmount;
}

void Sharpie::use() {
    if(_inkAmount > 0){
        _inkAmount--;
    } else {
        std::cout << "No more ink, fill up ASAP!!" << std::endl;
    }
}

string Sharpie::getColor(){
    return _color;
}

float Sharpie::getWidth(){
    return _width;
}

float Sharpie::getInkAmount() {
    return _inkAmount;
}
