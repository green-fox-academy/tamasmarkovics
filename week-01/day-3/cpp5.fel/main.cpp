#include <iostream>
#include <string>

int main() {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.
    int oddeven =0;
    std::cout << "Give me a number pls:" << std::endl;
    std::cin >> oddeven;
    if(oddeven%2 == 0){
        std::cout << "Even" << std::endl;
    }
    else std::cout << "Odd :(" << std::endl;
    std::cout << std::endl;

    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot
    int num = 0;
    std::cout << "Give me a number pls:" << std::endl;
    std::cin >> num;
    if (num < 1){
        std::cout << "Not enough" << std::endl;
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
    std::cout << std::endl;

    // Write a program that asks for two numbers and prints the bigger one
    int fir = 0;
    int secc = 0;
    std::cout << "Two num pls ty :)" << std::endl;
    std::cin >> fir >> secc;
    if (fir <= secc) {
        std::cout << "Wrong order!" << std::endl;
    } else if (fir > secc){
        std::cout << fir<< " is bigger"<< std::endl;
    }else
        std::cout << secc<< " is bigger"<< std::endl;
    std::cout << std::endl;


    // Write a program that asks for two numbers
    int boiz =0;
    int girls =0;
    std::cout << "How many girls and boiz go to the party?" << std::endl;
    std::cin >> girls >> boiz;
    // The first number represents the number of girls that comes to a party, the
    // second the boys
    // It should print: The party is excellent!
    // If the the number of girls and boys are equal and 20 or more people are coming to the party
    if (girls == 0) {
        std::cout <<"Sausage party!" << std::endl;
    } else if (girls == boiz && (girls + boiz) > 20){
        std::cout << "Excellencio!" << std::endl;
    } else if ((girls + boiz) > 20){
        std::cout << "Quite cool party!" << std::endl;
    } else std::cout << "Meh party :(" << std::endl;
    // It should print: Average party...
    // If there are less people coming than 20
    //
    // It should print: Sausage party
    // If no girls are coming, regardless the count of the people
    return 0;
}