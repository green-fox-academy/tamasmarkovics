#include <stdio.h>
#include "circle.h"


int main()
{
    // define a variable called PI with the value of 3.14
    // create a function which takes the radius of a circle as a parameter
    // and return the area of that cirle
    // area = radius * radius * PI

    double rad = 0;
    printf("Give me a radius!\n");
    scanf("%lf", &rad);

    printf("circumference = 2 * radius * PI = %0.2lf\n", circumference(rad));
    printf("area = radius * radius * PI = %0.2lf\n", area(rad));

    return 0;
}