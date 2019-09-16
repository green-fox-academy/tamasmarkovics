#include <iostream>
#include <map>
#include <string>


int main() {
    std::map<std::string, double> prices = {{"Milk", 1.07}, {"Rice", 1.59}, {"Eggs", 3.14},
                                              {"Cheese", 12.60}, {"Chicken Breast", 9.40}, {"Apples", 2.31},
                                              {"Tomato", 2.58}, {"Potato", 1.75}, {"Onion", 1.10}};

    std::map<std::string, double> Bob = {{"Milk", 3}, {"Rice", 2}, {"Eggs", 2},
                                         {"Cheese", 1}, {"Chicken Breast", 4}, {"Apples", 1},
                                         {"Tomato", 2}, {"Potato", 1}};

    std::map<std::string, double> Alice = {{"Rice", 1}, {"Eggs", 5},
                                         {"Chicken Breast", 2}, {"Apples", 1}, {"Tomato", 10}};

    double BobPays = 0;
    double AlicePays = 0;

    for (std::pair<std::string, double> myPairB : Bob){
        for (std::pair<std::string, double> myPairP : prices){
            if (myPairB.first == myPairP.first){
                BobPays += myPairB.second * myPairP.second;
            }
        }
    }
    std::cout << "Bob pays " << BobPays << std::endl;

    for (std::pair<std::string, double> myPairA : Alice){
        for (std::pair<std::string, double> myPairP : prices){
            if (myPairA.first == myPairP.first){
                AlicePays += myPairA.second * myPairP.second;
            }
        }
    }
    std::cout << "Alice pays " << AlicePays << std::endl;

    return 0;
}