#include <iostream>

int index(int arr[], int lenght, int search);

int main() {

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array
    int arr[5];
    std::cout << "gimme 5 integers" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << &arr[i] << ": " << arr[i] << std::endl;
    }


    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    std::cout << index(arr, 5, 15);
    return 0;
}


int index(int arr[], int lenght, int search){
    int *sajt = &arr[0];
    for (int i = 0; i < lenght; ++i, sajt++) {
        if (*sajt == search){
            return i;
        }
    }
    return -1;
}