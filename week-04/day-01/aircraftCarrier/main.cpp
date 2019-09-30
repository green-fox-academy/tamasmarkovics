#include <iostream>
#include "Carrier.h"

int main() {
    Carrier ussFuckYou(1000, 2000);
    F16 f;
    F16 c;
    F16 k;
    F35 t;
    F35 h;

    ussFuckYou.add(&f);
    ussFuckYou.add(&c);
    ussFuckYou.add(&k);
    ussFuckYou.add(&t);
    ussFuckYou.add(&h);

    ussFuckYou.fill();


    return 0;
}