#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> names;
    std::cout << names.size() << std::endl;
    names.push_back("Giza");
    std::cout << "R U MPTY? " << names.empty() << std::endl;
    names.push_back("Anna");
    names.push_back("Jonniboi");
    std::cout << "No of elements: " << names.size() << std::endl;
    std::cout << "Third element: " << names.at(2) << std::endl;
    for (int i = 0; i < names.size(); ++i) {
        std::cout << names.at(i) << std::endl;
    }
    for (int i = 0; i < names.size(); ++i) {
        std::cout << i << ". " << names.at(i) << std::endl;
    }
    names.erase(names.begin()+ 1);
    for (int i = 0; i < names.size(); ++i) {
        std::cout << i << ". " << names.at(i) << std::endl;
    }
    names.clear();
    return 0;
}