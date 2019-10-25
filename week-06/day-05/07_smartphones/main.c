#include <stdio.h>
#include <string.h>


enum screen_size {
    SMALL,
    MEDIUM,
    BIG
};

typedef struct smartphone {
    char name[64];
    int year;
    enum screen_size size;
} smartphone_t;

void get_oldest_phone(char *return_name, smartphone_t *arr, int size);
int get_screen_size_count(smartphone_t *arr, int size, enum screen_size scsize);
int line_count (char *address);
int write_to_file (smartphone_t *arr, int size);
int get_price (smartphone_t phone);


int main()
{
    char *file_loc = "../smartphones.txt";
    FILE *fptr;
    int no_of_phones = line_count(file_loc);
    smartphone_t phones[no_of_phones];

    if(!(fptr = fopen(file_loc, "r"))) return -1;
    for (int i = 0; i < no_of_phones; i++) {
        int tmp;
        fscanf(fptr, "%s %d %d", phones[i].name, &phones[i].year, &tmp);
        phones[i].size = tmp >= 15 ? BIG : tmp < 12 ? SMALL : MEDIUM;
    }
    fclose(fptr);

    char oldest_phone[64];
    get_oldest_phone(oldest_phone, phones, no_of_phones);

    printf("%s is the oldest device in the database\nThere are %d phones with BIG screen\nThere are %d phones with SMALL screen",
            oldest_phone,
            get_screen_size_count(phones, no_of_phones, BIG),
            get_screen_size_count(phones, no_of_phones, SMALL)
            );

    write_to_file(phones, no_of_phones);

    return 0;
}

int get_screen_size_count(smartphone_t *arr, int size, enum screen_size scsize)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i].size == scsize) {
            count ++;
        }
    }
    return count;
}

int line_count (char *address)
{
    FILE *ffptr;
    if (!(ffptr = fopen(address, "r"))) return -1;

    int count = 0;
    char line[100];
    while (fgets (line , 100 , ffptr)) {
        count++;
    }
    fclose(ffptr);
    return count;
}

void get_oldest_phone(char* return_name, smartphone_t *arr, int size)
{
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i].year < arr[index].year) index = i;
        //index = arr[i].year < arr[index].year ? i : index;
    }
    strcpy(return_name, arr[index].name);
}

int get_price (smartphone_t phone)
{
    int price = 300;
    if (phone.size == BIG) price *=2;
    if (phone.size == MEDIUM) price +=100;
    price -= (5 <= 2019 - phone.year ? 5 : 2019-phone.year) * 50;
    return price;
}

int write_to_file (smartphone_t *arr, int size)
{
    FILE *wptr;
    if (!(wptr = fopen("../prices.txt", "w"))){
        printf("so that didnt work");
        return -1;
    }

    fprintf(wptr, "%s\t%d", arr[0].name, get_price(arr[0]));
    for (int i = 1; i < size; ++i) {
        fprintf(wptr, "\n%s\t%d", arr[i].name, get_price(arr[i]));
    }

    fclose(wptr);
    return 0;
}