#include <iostream>
#include "Carrier.h"

int main() {

    Carrier ussFFS(1000, 2000);
    Carrier ussGetMeOut(100, 600);
    F16 f;
    F16 c;
    F16 k;
    F35 t;
    F35 h;
    F16 i;
    F16 s;

    ussFFS.add(&f);
    ussFFS.add(&c);
    ussFFS.add(&k);
    ussFFS.add(&t);
    ussFFS.add(&h);
    ussGetMeOut.add(&i);
    ussGetMeOut.add(&s);

    ussFFS.fill();
    ussGetMeOut.fill();
    ussFFS.fight(&ussGetMeOut);
    ussFFS.fill();

    ussFFS.getStatus();

    return 0;
}