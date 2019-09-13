#include <iostream>

using namespace std;

int main() {
    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end
    string animals[3] = {"koal", "pand", "zebr"};
    for (int a = 0; a < 3; ++a) {
        animals[a] += "a";
        cout << animals[a] << ", ";

    }
    cout << endl;

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`
    string abc[3] = {"first", "second", "third"};
    string temp;
    temp = abc[0];
    abc[0] = abc[2];
    abc[2] = temp;
    for (int i = 0; i < 3; ++i) {
        cout << abc[i] << ", ";
    }
    cout << endl;

    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`
    int ai[5] = {3, 4, 5, 6, 7};
    int sum = 0;
    for (int j = 0; j < 5; ++j) {
        sum += ai[j];
    }
    cout << sum << endl;

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
    int aj[5] = {3, 4, 5, 6, 7};
    int tempAj;
    for (int k = 0; k < 2; k++) {
        tempAj = aj[k];
        aj[k] = aj[5 - k - 1];
        aj[5 - k -1] = tempAj;
    }
    for (int m = 0; m < 5; ++m) {
        cout << aj[m] << ", ";
    }
    cout << endl;



    return 0;
}