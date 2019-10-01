#ifndef DEVICES_SCANNER_H
#define DEVICES_SCANNER_H
#include <iostream>

class Scanner {
public:
    virtual void scan();
    Scanner(int speed);

protected:
    int _speed;

};


#endif //DEVICES_SCANNER_H
