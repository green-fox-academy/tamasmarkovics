#ifndef DEVICES_PRINTER_H
#define DEVICES_PRINTER_H

#include <iostream>
#include <string>
using std::string;

class Printer {
public:
    virtual string getSize() = 0;
    void print();

protected:

};


#endif //DEVICES_PRINTER_H
