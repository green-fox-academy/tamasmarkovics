#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct point {
    double x;
    double y;
} point_t;

double distance(point_t a, point_t b)
{
    return (sqrt(pow(a.x - b.x, 2) + pow(a.y + b.y, 2)));
};

int main()
{
	point_t a = {0,0};
	point_t b = {3, 4};
	printf("%.0lf", distance(a, b));
	return 0;
}