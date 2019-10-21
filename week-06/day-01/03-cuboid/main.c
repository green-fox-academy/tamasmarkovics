#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:

    int wid, hei, dep;
    scanf("%d%d%d", &wid, &hei, &dep);

    printf("Surface Area: %d\nVolume: %d", wid * hei * 2 + wid * dep * 2 + dep * hei * 2, wid * dep * hei);
    return 0;
}