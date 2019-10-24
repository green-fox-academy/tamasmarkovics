#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer my_computer = {4, 1, 3};
    Notebook my_notebook = {3, 2, 3};
    printf("My computer has a %.2f GHz cpu speed, a %d ram size, and %d bits.\n", my_computer.cpu_speed_GHz, my_computer.ram_size_GB, my_computer.bits);
    printf("My notebook has a %.2f GHz cpu speed, a %d ram size, and %d bits.\n", my_notebook.cpu_speed_GHz, my_notebook.ram_size_GB, my_notebook.bits);

    return 0;
}