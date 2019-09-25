#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H


class Car {
public:
    Car(int capacity, int gasAmount);
    bool isFull();
    void fill();
private:
    int _gasAmount;
    int _capacity;
};


#endif //PETROLSTATION_CAR_H
