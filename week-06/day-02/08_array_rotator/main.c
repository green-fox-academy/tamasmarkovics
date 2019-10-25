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
           (byte & 0x01 ?'1' : '0'));
}

void array_rotator(void *ptr, uint32_t bytes, uint32_t rotation_count, int right) {
    /* This function should rotate the ptr buffer bits by rotation_count to left or right direction.
     * The rotation direction is right if the right parameter is positive, left otherwise.
     * E.g. ptr ->  |   0xAA    |    0x55   |    0x23   |
     *              | 1010 1010 | 0101 0101 | 0010 0011 |
     * array_rotator(ptr, 3, 2, 1) result is:
     *              |   0xEA    |    0x95   |    0x48   |
     *              | 1110 1010 | 1001 0101 | 0100 1000 |
     */

    uint8_t *my_ptr = ptr;
    rotation_count %= (8 * bytes);
    int32_t start = rotation_count / 8;
    int32_t rotate = rotation_count % 8;
    uint8_t temp_array[bytes];
    if (right > 0) {
        for (int32_t i = 0; i < bytes; i++) {
            temp_array[i] = ((*(my_ptr + ((start + i) % bytes)) >> rotate) |
                                    (*(my_ptr + ((start + i + 1) % bytes)) << (8 - rotate)));
        }
    } else {
        for (int i = 0; i < bytes; i++) {
            temp_array[i] = ((*(my_ptr + ((start + i) % bytes)) << rotate) |
                            (*(my_ptr + ((start + i + 1) % bytes)) >> (8 - rotate)));
        }
    }

    my_ptr = ptr;
    for (int i = 0; i < bytes; i++) {
        *my_ptr = temp_array[i];
        my_ptr++;
    }

}

int main()
{
    int rotations = 3;
    uint8_t test_array1[] = {0b1000000, 0b00000000, 0b00000000};
    for (int i = 0; i < sizeof(test_array1); i++) {
        print_binary(test_array1[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++) {
        array_rotator(test_array1, sizeof(test_array1), 1, 1);
        for (int i = 0; i < sizeof(test_array1); i++) {
            print_binary(test_array1[i]);
        }
        printf("\n");
    }

    uint8_t test_array2[] = {0b00000000, 0b10000000, 0b00000001, 0b10000000};
    for (int i = 0; i < sizeof(test_array2); i++) {
        print_binary(test_array2[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        array_rotator(test_array2, sizeof(test_array2), 1, -1);
        for (int i = 0; i < sizeof(test_array2); i++) {
            print_binary(test_array2[i]);
        }
        printf("\n");
    }

    return 0;
}





/*  no idea if useful, better keep it
void array_rotator(void *ptr, uint32_t bytes, uint32_t rotation_count, uint8_t right) {
    uint8_t *my_ptr = ptr;
    rotation_count %= (8 * bytes);
    int32_t start = rotation_count / 8;
    int32_t rotate = rotation_count % 8;
    uint8_t temp_array[bytes];
    uint8_t temp_array1[bytes];
    for (uint32_t i = 0; i < bytes; i++) {
        temp_array[i] = (*(my_ptr + ((start + i) % bytes)) >> rotate);
        temp_array1[i] = (*(my_ptr + ((start + i) % bytes)) << 8 - rotate);
    }

    my_ptr = ptr;
    for (int i = 0; i < bytes; i++) {
        *my_ptr = temp_array[(i + start) % bytes] | temp_array1[(i + start + 1) % bytes];
        my_ptr++;
    }
}

void array_rotatorL(void *ptr, uint32_t bytes, uint32_t rotation_count, uint8_t right) {
    uint8_t *my_ptr = ptr;
    rotation_count %= (8 * bytes);
    int32_t start = rotation_count / 8;
    int32_t rotate = rotation_count % 8;
    uint8_t temp_array[bytes];
    uint8_t temp_array1[bytes];
    for (int32_t i = 0; i < bytes; i++) {
        temp_array[i] = (*(my_ptr + ((start + i) % bytes)) << rotate);
        temp_array1[i] = (*(my_ptr + ((start + i) % bytes)) >> 8 - rotate);
    }

    my_ptr = ptr;
    for (int i = 0; i < bytes; i++) {
        *my_ptr = temp_array[(i + start) % bytes] | temp_array1[(i + start - 1) % bytes];
        my_ptr++;
    }
}
 */