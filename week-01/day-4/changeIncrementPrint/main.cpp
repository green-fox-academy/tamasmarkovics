#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* args[]) {

    // - Create an array variable named `s`
    //   with the following content: `[1, 2, 3, 8, 5, 6]`
    // - Change the 8 to 4
    // - Print the fourth element
    int s[] = {1, 2, 3 , 8, 5, 6};
    s[3] = 4;
    cout << s[3] << endl;
    // - Create an array variable named `t`
    //    with the following content: `[1, 2, 3, 4, 5]`
    // - Increment the third element
    // - Print the third element
    int t[] = {1, 2, 3, 4, 5,};
    t[2]++;
    cout << t[2] << endl;
    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`
    int numbers[] = {4, 5, 6, 7};
    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) {
        cout << numbers[i] << endl;
    }
    return 0;
}