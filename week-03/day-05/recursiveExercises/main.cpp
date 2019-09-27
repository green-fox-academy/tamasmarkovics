#include <iostream>

int add (int n){
    if (n == 1){
        return 1;
    } else return n + add(n-1);
}


int sumDigit (int n){
    if (n == 0){
        return 0;
    } else return n % 10 + sumDigit(n / 10);
}


int main() {
    int n = 10;
    std::cout << "Adding numbers until " << n << " equals: " << add(n) << std::endl;
    int sum = 5555;
    std::cout << "Summing digits of " << sum << " equals: " << sumDigit(sum) << std::endl;



    return 0;
}