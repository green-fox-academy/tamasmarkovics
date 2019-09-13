#include <iostream>

void Sort(int arr[], int n, bool f);

int main() {
    //  Create a function that takes a list of numbers as parameter
    //  Don't forget you have to pass the size of the list as a parameter as well
    //  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
    //  Make a second boolean parameter, if it's `true` sort that list descending
    int n;
    std::cout << "Giv me the number of numbers of numbers!" << std::endl;
    std::cin >> n;
    int list[n];
    std::cout << "Give me the numbers!" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> list[i];
    }
    bool direction;
    std::cout << "How would you like it sorted? 1/0" << std::endl;
    std::cin >> direction;
    Sort(list, n, direction);
    return 0;
}

void Sort(int arr[], int n, bool f)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (((arr[j] < arr[j + 1]) && f) || ((arr[j] > arr[j + 1]) && !(f))) {
                std::swap(arr[j], arr[j + 1]);
            };
        }
    }
    for (int k = 0; k < n; ++k) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;
}