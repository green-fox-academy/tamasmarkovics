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

uint8_t rotateL(uint8_t byte, uint8_t times)
{
    return ((byte << times) | (byte >> (8-times)));
}

uint8_t rotateR(uint8_t byte, uint8_t times)
{
    return ((byte >> times) | (byte << (8-times)));
}


int main() {

    uint8_t byte = 0b11100111;
    PrintBinary(rotateL(byte, 4));
    //0111 1110
    PrintBinary(rotateL(byte, 1));
    //1100 1111
    byte = 0b10000111;
    PrintBinary(rotateL(byte, 3));
    //0011 1100

    byte = 0b11100111;
    PrintBinary(rotateR(byte, 4));
    //0111 1110
    PrintBinary(rotateR(byte, 1));
    //1111 0011
    byte = 0b10000111;
    PrintBinary(rotateR(byte, 3));
    //1111 0000


    return 0;
}