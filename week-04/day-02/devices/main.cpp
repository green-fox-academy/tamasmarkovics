#include "Copier.h"
#include "Printer3D.h"
#include <vector>
using std::vector;

int main() {
    // Create a vector that holds Printer* objects
    vector<Printer*> printers;
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.
    Printer2D printer1(300, 125);
    Printer2D printer2(500, 120);
    Printer2D printer3(400, 125);
    Printer3D printer4(100, 120, 150);
    Printer3D printer5(150, 140, 110);
    Copier copycat(500,500,500);
    printers.push_back(&printer1);
    printers.push_back(&printer2);
    printers.push_back(&printer3);
    printers.push_back(&printer4);
    printers.push_back(&printer5);
    printers.push_back(&copycat);

    for (int i = 0; i < printers.size(); ++i) {
        printers[i]->print();
    }

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    vector<Scanner*> szcennerz;
    Scanner scan1(300);
    Scanner scan2(400);
    Copier koopier1(100,200,400);
    Copier koopier2(300,400,100);
    szcennerz.push_back(&scan1);
    szcennerz.push_back(&scan2);
    szcennerz.push_back(&koopier1);
    szcennerz.push_back(&koopier2);

    // Iterate through the vector and invoke scan function on all of them
    for (int i = 0; i < szcennerz.size(); ++i) {
        szcennerz[i]->scan();
    }

    // Create a Copier object and invoke copy function on it.
    koopier2.copy();
}