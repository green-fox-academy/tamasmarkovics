#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H
#include <iostream>
#include <string>
using std::string;

class Sharpie {
public:
    Sharpie(string color, float width);
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

/*
Create Sharpie class
We should know about each sharpie their color (which should be a string),
                                        width (which will be a floating point number),
                                        inkAmount (another floating point number)
When creating one, we need to specify the color and the width

Every sharpie is created with a default 100 as inkAmount

We can use() the sharpie objects which decreases inkAmount
 */
