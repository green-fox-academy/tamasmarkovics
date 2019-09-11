#include <iostream>
#include <string>
#include <math.h>

int main(int argc, char* args[]) {

    int a = 3;
    // make the "a" variable's value bigger by 10
    a+=10;
    std::cout << a << std::endl;

    int b = 100;
    // make b smaller by 7
    b-=7;
    std::cout << b << std::endl;

    int c = 44;
    // please double c's value
    c*=2;
    std::cout << c << std::endl;

    int d = 125;
    // please divide by 5 d's value
    d/=5;
    std::cout << d << std::endl;

    int e = 8;
    // please cube of e's value
    e*e;
    std::cout << e << std::endl;

    int f1 = 123;
    int f2 = 345;
    bool big=f1>f2;
    // tell if f1 is bigger than f2 (print as a boolean)
    std::cout<< big << std::endl;
    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)
    big=(g2*2)>g1;
    std::cout<< big << std::endl;
    int h = 135798745;
    // tell if it has 11 as a divisor (print as a boolean)
    if (h/11.0==h/11){
        std::cout<< 1<<std::endl;
    }else
    {
        std::cout<<0<<std::endl;
    }

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
    if (i1>pow(i2, 0.5)&&i1<pow(i2, 2)){
        std::cout<< 1<<std::endl;
    }else
    {
        std::cout<<0<<std::endl;
    }
    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)
    if ((j/3==j/3.0)||(j/5==j/5.0)){
        std::cout<< 1<<std::endl;
    }else
    {
        std::cout<<0<<std::endl;
    }
    std::cout<<std::endl;
    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    int DayInSec=24*60*60;
    int rem=DayInSec-currentHours*60*60-currentMinutes*60-currentSeconds;
    std::cout<<rem<<std::endl;

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    float hei=10;
    float dep=20;
    float wid=50;
    std::cout<<std::endl<<"Surface Area: "<< (hei*dep+hei*wid+wid*dep)*2<<std::endl;
    std::cout<<"Surface Area: "<< hei*dep*wid <<std::endl;



    return 0;
}