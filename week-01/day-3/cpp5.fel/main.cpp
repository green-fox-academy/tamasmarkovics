#include <iostream>

int main() {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.
    int oddeven=0;
    std::cout<<"Give me a number pls:"<<std::endl;
    std::cin>> oddeven;
    if(oddeven/2==oddeven/2.0){
        std::cout<<"Even"<<std::endl;
    }
    else std::cout<<"Odd :("<< std::endl;
    std::cout<<std::endl;

    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot
    int num=0;
    std::cout<<"Give me a number pls:"<<std::endl;
    std::cin>>num;
    if (num<1){
        std::cout<<"Not enough"<<std::endl;
    }else switch(num) {
            case 1:
                std::cout << "One" << std::endl;
                break;
            case 2:
                std::cout << "Two" << std::endl;
                break;
            default:
                std::cout << "Too bigg" << std::endl;
                break;
        }

    // Write a program that asks for two numbers and prints the bigger one
    int fir=0;
    int secc=0;
    std::cout<<"Two num pls ty :)"<<std::endl;
    std::cin>>fir>>secc;

    return 0;
}