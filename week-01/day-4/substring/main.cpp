#include<iostream>
#include <string>
using namespace std;
//  Create a function that takes two strings as a parameter
//  Returns the starting index where the second one is starting in the first one
//  Returns `-1` if the second string is not in the first one

int subString(string str, string keyword);

int main() {

    char str[] = ("this is what I'm searching in");
    char str2[] = ("searching");

    // Should print: '17'
    cout << subString("this is what I'm searching in", "searching") << endl;

    // Should print: '-1'
    cout << subString("this is what I'm searching in", "not") << endl;
    return 0;
}

int subString(string str, string keyword) {
    // Find first occurrence of 'g'
    size_t found = str.find(keyword);
    if (found != string::npos) {
        return found;
    } else return -1;
}