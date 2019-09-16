#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> productData = {{"Eggs", 200}, {"Milk", 200}, {"Fish", 400},
                                              {"Apples", 150}, {"Bread", 50}, {"Chicken", 550}};

    std::cout << productData["Fish"] << std::endl;

    int expensive = 0;
    for (std::pair<std::string, int> myPair : productData){
         if (myPair.second > expensive){
          expensive = myPair.second;
        }
    }
    std::cout << expensive << std::endl;

    int sum = 0;
    for (std::pair<std::string, int> myPair2 : productData){
        sum += myPair2.second;
    }
    std::cout << sum / productData.size() << std::endl;

    int count = 0;
    for (std::pair<std::string, int> myPair3 : productData){
        if (myPair3.second < 300){
            count++;
        }
    }
    std::cout << count << std::endl;
    bool isthere = false;
    for (std::pair<std::string, int> myPair4 : productData){
        if (myPair4.second == 125){
            isthere = true;
            break;
        } else {isthere = false;}
    }
    if (isthere){
        std::cout << "There is." << std::endl;
    } else {std::cout << "Nothing sry, you cheap bastard" << std::endl;}

    int csipeszt = 0;
    for (std::pair<std::string, int> myPair4 : productData){
        if (myPair4.second < csipeszt || csipeszt == 0){
            csipeszt = myPair4.second;
        }
    }
    std::cout << csipeszt << std::endl;

    return 0;
}

//    std::cout << phoneList["William A. Lathan"] << std::endl;
//    for (std::pair<std::string, std::string> myPair : phoneList){
//        if (myPair.second == "307-687-2982"){
//            std::cout << myPair.first << std::endl;
//        }
//    }