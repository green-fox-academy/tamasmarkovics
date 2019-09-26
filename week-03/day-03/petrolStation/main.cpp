#include <iostream>
#include "Station.h"
#include "Car.h"


int main() {

    Car blue(10, 4);
    Car green(9, 6);
    Car black(4,2);
    Station MOL;
    MOL.fill(blue);
    MOL.fill(green);
    MOL.fill(black);

    std::cout << blue.isFull() << std::endl;
    return 0;
}