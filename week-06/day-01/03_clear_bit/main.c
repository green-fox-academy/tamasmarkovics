#include <stdio.h>
#include <stdint.h>

void print_binary(uint8_t byte) {
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

uint8_t clear_bit(uint8_t byte, int pos)
{
    uint8_t temp = 0b00000001;
    return(~(temp << pos) & byte);
}

int main()
{
    uint8_t byte = 0b11111111;

    print_binary(clear_bit(byte, 2));
    print_binary(clear_bit(byte, 4));
    /*
     * Write a function called ClearBit which takes a byte and a bit position
     * and clears the bit of byte in the specified bit position to 0.
     * E.g. byte = 0b1100, bit position = 2 => returns with 0b1000
     */


    return 0;
}