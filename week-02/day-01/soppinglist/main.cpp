#include <iostream>
#include <vector>
#include <string>

int main() {
    bool exists;
    std::vector<std::string> list = {"eggs", "milk", "fish", "apples", "bread","chicken"};
    for (int i = 0; i < list.size() ; ++i) {
        if (list.at(i) == "milk") {
            exists = true;
            break;
        } else { exists = false; }
    }
    if (exists) {
        std::cout << "Milk is on the list!" << std::endl;
    } else {std::cout << "You no gettin milk anytime soon.";}

    for (int j = 0; j < list.size() ; ++j) {
        if (list.at(j) == "bananas") {
            exists = true;
            break;
        } else { exists = false; }
    }
    if (exists) {
        std::cout << "Banana is on the list!" << std::endl;
    } else {std::cout << "You no gettin bananas anytime soon.";}

    return 0;
}