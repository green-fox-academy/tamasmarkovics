#include <iostream>
#include <string>

using namespace std;

string createPali(string& pali);
int main() {
    //Create a function named create palindrome following your current language's style guide. It should take a string,
    //create a palindrome from it and then return it.
    string toBePaliD;
    cout << "Give me a string!" << endl;
    cin >> toBePaliD;
    cout << createPali(toBePaliD);
    return 0;
}
string createPali(string& pali){
    int size = pali.length();
    for (int i = size; i > 0; i--) {
        pali += pali[i-1];
    }
    return pali;
}