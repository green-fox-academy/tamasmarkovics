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

uint8_t count_ones(uint8_t byte)
{
    uint8_t count = 0;
    for (int i = 0; i < 8; i++) {
        if (byte & 1) {
            count++;
        }
        byte >>= 1;
    }
    return count;
}

uint8_t count_zeros(uint8_t byte)
{
    uint8_t count = 0;
    for (int i = 0; i < 8; i++) {
        if (~byte & 1) {
            count++;
        }
        byte >>= 1;
    }
    return count;
}

int main() {
    /* 1.
     * Write a function called CountOnes which takes a byte returns
     * with the number of one bits in it.
     * E.g. byte = 0b1101 => returns with 3
     */
    uint8_t byte = 0b11100111;
    printf("%d\n", count_ones(byte));
    printf("%d\n", count_zeros(byte));

    byte = 0b10000111;
    printf("%d\n", count_ones(byte));
    printf("%d\n", count_zeros(byte));

    /* 2.
     * Write a function called CountZeros which takes a byte returns
     * with the number of zero bits in it.
     * E.g. byte = 0b1000 => returns with 3
     */

    return 0;
}