#include <iostream>
#include <string>
#include <map>
using std::cin;
using std::cout;
using std::endl;


int main() {
    std::map<int, std::string> map1;
    map1[97] = "a";
    map1[98] = "b";
    map1[99] = "c";
    map1[65] = "A";
    map1[66] = "B";
    map1[67] = "C";

    //for (std::map<int, std::string>::iterator it = map1.begin(); it != map1.end(); it++){}

    for(auto pair: map1){
        cout << pair.first << endl;
    }
    for(auto pair: map1){
        cout << pair.second << endl;
    }

    map1[68] = "D";

    cout << "No of tings " << map1.size() << endl;

    cout << map1[99] << endl;
    map1.erase(map1.find(97));
    cout << "No of tings " << map1.size() << endl;

    cout << map1.count(100) << endl;
    map1.clear();
    return 0;
}