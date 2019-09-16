#include <iostream>
#include <vector>
#include <string>


int main() {
    std::vector<std::string> listA= { "Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    std::vector<std::string> listB= { "Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    int at=0;
    bool questionmark = false;
    for (int i = 0; i < listB.size() && !questionmark; ++i) {
        questionmark = listB[i] == "Durian";
        at = i;
    }
    listB.erase(listB.begin() + at);
    std::cout << listB.size() << std::endl;
    listA.insert(listA.begin()+3, "Kecskesajt");

    for (int i = 0; i < listB.size() && questionmark; ++i) {
        questionmark = listB[i] != "Avocado";
        at = i;
    }
    std::cout << at << std::endl;


    at = -1;
    for (int i = 0; i < listB.size() && !questionmark; ++i) {
        questionmark = (listB[i] == "Durian");
        if (questionmark) {
            at = i;
        }
    }

    std::cout << "Durian is " << questionmark << " in the list"<< std::endl;
    std::cout << "Durian is at: "<< at << std::endl;
    listB.insert(listB.end(),  {"Fruit" , "Pamela"});
    questionmark= false;
    at = -1;
    for (int i = 0; i < listB.size() && !questionmark; ++i) {
        questionmark = (listB[i] == "Fruit");
        if (questionmark) {
            at = i;
        }
    }

    std::cout << listA[3] << std::endl;


    return 0;
}