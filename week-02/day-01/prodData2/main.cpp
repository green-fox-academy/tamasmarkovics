#include <iostream>
#include <map>
#include <string>
int main() {
    std::map<std::string, int> productData = {{"Eggs", 200}, {"Milk", 200}, {"Fish", 400},
                                              {"Apples", 150}, {"Bread", 50}, {"Chicken", 550}};

    std::cout << "What costs less than 201" << std::endl;
    for (std::pair<std::string, int> myPair : productData){
        if (myPair.second < 201){
            std::cout << myPair.first << std::endl;
        }
    }

    std::cout << std::endl << "What costs more than 150" << std::endl;
    for (std::pair<std::string, int> myPair : productData){
        if (myPair.second > 150){
            std::cout << myPair.first << " costs " << myPair.second << std::endl;
        }
    }





    return 0;
}