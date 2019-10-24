#include <stdio.h>

/*
Create a sandwich struct
It should store:
*/
typedef struct sandwich {
    char* name;
    float price;
    float weight;
} sandwich_t;


 /*
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

float what_does_it_cost(sandwich_t my_sandwich, int number)
{
    return my_sandwich.price * number;
}

int main()
{
    sandwich_t a_sandwich = {"whopper", 5.25f, 0.4f};
    printf("Your order costs %.2f JMF.\n",what_does_it_cost(a_sandwich, 4));
    return 0;
}
