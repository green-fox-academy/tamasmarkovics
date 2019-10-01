#include <iostream>
#include "ElectricGuitar.h"
#include "Violin.h"
#include "BassGuitar.h"


int main( int argc, char* args[] )
{

    std::cout << "Test 1, create Electric Guitar, Bass Guitar and Violin with default strings." << std::endl;
    ElectricGuitar guitar;
    BassGuitar bassGuitar;
    Violin violin;

    std::cout<< "Test 1 Play" << std::endl;
    guitar.play();
    bassGuitar.play();
    violin.play();

    std::cout << "Test 2, create Electric Guitar, Bass Guitar." << std::endl;
    ElectricGuitar guitar2;
    BassGuitar bassGuitar2;

    std::cout << "Test 2 Play" << std::endl;
    guitar2.play();
    bassGuitar2.play();
}