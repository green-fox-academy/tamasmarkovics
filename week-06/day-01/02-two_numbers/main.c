#include <stdio.h>

int main() {

    int a = 22, b = 13;

    int add = a + b;
    int subs = a - b;
    int multi = a * b;
    float divi = a / (float)b;
    int rem = a % b;

    printf("%d\n%d\n%d\n%f\n%d\n", add, subs, multi, divi, rem);

    return 0;
}