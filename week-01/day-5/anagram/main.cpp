#include <iostream>
#include <string>
using namespace std;

bool anagram(string input1, string input2);

int main() {
    //Create a function named is anagram following your current language's style guide. It should take two strings and
    // return a boolean value depending on whether its an anagram or not.
    string input1;
    string input2;
    cout << "Give me 2 string to compare!" << endl;
    cin >> input1 >> input2;
    cout << anagram(input1, input2) << endl;
    return 0;
}

bool anagram(string input1, string input2){
    bool sofar;
    if (input1.length() == input2.length()){
        sofar = 1;
        for (int i = 0; ((i < input1.length()) && (sofar != 0)); ++i) {
            if (input1[i] == input2[input2.length() - 1 - i]){
                sofar = 1;
            } else {sofar = 0;};
        }
    } else sofar = 0;

    return sofar;
}