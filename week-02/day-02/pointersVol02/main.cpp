#include <iostream>

void swapper(int *a, int *b);
int *minimum(int arr[], int lenght);

int main() {
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};

    std::cout << minimum(numbers, 7) << ": " << *minimum(numbers, 7) << std::endl;


    // Create a function which swaps the values of 'a' and 'b' variables.
    // This time use a void function and pointers.
    int a = 10;
    int b = 316;

    swapper(&a, &b);

    std::cout << "a = " << a << " &  b = " << b << std::endl;

    return 0;
}


int *minimum(int arr[], int lenght){
    int *min = &arr[0];
    for (int i = 0; i < lenght; ++i) {
        if (arr[i] < *min){
            min = &arr[i];
        }
    }
    return min;
}


void swapper(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}