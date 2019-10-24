#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct house {
    char* adress;
    int price;
    int room_no;
    int area;
} house_t;

int worth(house_t hus)
{
    return hus.price / hus.area <= 400;
}

int count_if_worth(house_t *arr, int size)
{
    int cunt = 0;
    for (int i = 0; i < size; ++i) {
        cunt += worth(arr[i]);
    }
    return cunt;
}

int main()
{
    house_t A66;
    A66.price = 20200000;
    A66.area = 10000;

    house_t a = {"", 543, 1, 43};
    house_t b = {"", 843, 1, 453};
    house_t c = {"", 643, 1, 3};

    //printf("%d", worth(A66));

    house_t street[] = {A66, a, b, c};
    printf("%d is worthy of my time!\n", count_if_worth(street, 4));
    return 0;
}