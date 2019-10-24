#include <stdio.h>
#include <string.h>


/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

typedef enum digivolution {
    baby,
    in_training,
    rookie,
    champion,
    ultimate,
    mega
} digivolution_t;


//SHOULDEV BEEN ALLCAPS
typedef struct digimon {
    char *name;
    int health;
    int age;
    char *tamer;
    digivolution_t lvl;
} digimon_t;

digimon_t create_digimon(char *name, int health, int age, char *tamer, digivolution_t level)
{
    digimon_t new;
    new.age = age >= 0 ? age : 0;
    new.health = (health >= 0 && health <= 100) ? health : health < 0 ? 0 : 100;
    new.lvl = level;
    new.name = strcmp(name, "") ? name : "unknown";
    new.tamer = strcmp(tamer, "") ? tamer : "unknown";
    return new;
}

//1) Get minimum health index
int get_min_hp(digimon_t* *arr, int size)
{
    int min_hp = 100;
    for (int i = 0; i < size; ++i) {
        min_hp = arr[i]->health < min_hp ? arr[i]->health : min_hp;
    }
    return min_hp;
}

//2) Get same digivolution level count
int get_same_lvl(digimon_t* *arr, int size, digivolution_t level)
{
    int same = 0;
    for (int i = 0; i < size; ++i) {
        same += arr[i]->lvl == level;
    }
    return same;
}

//4) Get average health of the same tamer
double average_hp_stamer(digimon_t* *arr, int size, char * a_tamer)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        sum += strcmp(arr[i]->tamer, a_tamer) ? 0 : arr[i]->health;
        count += strcmp(arr[i]->tamer, a_tamer) ? 0 : 1;
    }
    return sum / (double)count;
}


int main()
{
    digimon_t a = create_digimon("", 200, -1, "", baby);
    printf("name: %s, health: %d, age: %d, tamer: %s, level: %d\n", a.name, a.health, a.age, a.tamer, a.lvl);
    digimon_t b = create_digimon("dsa", 5, -1, "dsad", baby);
    digimon_t c = create_digimon("dsa", 76, -1, "dsad", baby);
    printf("name: %s, health: %d, age: %d, tamer: %s, level: %d\n", b.name, b.health, b.age, b.tamer, b.lvl);

    digimon_t* arr[] = {&a, &b, &c};

    printf("%d\n", get_min_hp(arr, 3));
    printf("%d\n", get_same_lvl(arr, 3, mega));
    printf("%0.2lf\n", average_hp_stamer(arr, 3, "dsad"));

    return 0;
}