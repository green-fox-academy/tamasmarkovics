#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> phoneList={
            {"William A. Lathan", "405-709-1865"},
            {"Hortensia E. Foster","606-481-6467"},
            {"Amanda D. Newland", "319-243-5613"},
            {"Brooke P. Askew", "307-687-2982"}};

    //std::cout << ""


    std::cout << phoneList["William A. Lathan"] << std::endl;
    for (std::pair<std::string, std::string> myPair : phoneList){
        if (myPair.second == "307-687-2982"){
            std::cout << myPair.first << std::endl;
        }
    }
    bool smthng = false;
    for (std::pair<std::string, std::string> myPair : phoneList){
        if (myPair.first == "Chris E. Myers"){
            std::cout << "His number is " << myPair.first << std::endl;
        } else smthng = true;
    }
    if (smthng){
        std::cout << "we aint have no number" << std::endl;
    }



    return 0;
}