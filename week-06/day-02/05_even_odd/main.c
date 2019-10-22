#include <stdio.h>
#include <stdint.h>

void PrintBinary(uint8_t byte) {
    printf("%c%c%c%c %c%c%c%c\n",
           (byte & 0x80 ? '1' : '0'),
           (byte & 0x40 ? '1' : '0'),
           (byte & 0x20 ? '1' : '0'),
           (byte & 0x10 ? '1' : '0'),
           (byte & 0x08 ? '1' : '0'),
           (byte & 0x04 ? '1' : '0'),
           (byte & 0x02 ? '1' : '0'),
           (byte & 0x01 ? '1' : '0'));
}

uint8_t is_odd(uint8_t byte)
{
    uint8_t temp = 1;
    return(byte & temp);
}

uint8_t is_even(uint8_t byte)
{
    uint8_t temp = 1;
    return((byte & temp) ^ temp);
}
int main() {

    /* 1.
     * Write a function called IsEven which takes a byte and returns with true
     * if byte is even. Use only bitwise operators!
     */

    /* 2.
     * Write a function called IsOdd which takes a byte and returns with true
     * if byte is odd. Use only bitwise operators!
     */

    uint8_t byte = 0b11010101;
    uint8_t bytei = 0b11010100;
    printf("%d\n", is_odd(byte));
    printf("%d\n", is_even(byte));

    printf("%d\n", is_odd(bytei));
    printf("%d\n", is_even(bytei));

    return 0;
}