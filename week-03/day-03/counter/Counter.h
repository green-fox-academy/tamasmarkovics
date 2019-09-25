#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter();
    Counter(int fieldValue);
    void add(int number);
    void add();
    void reset();

    int get();

private:
    int _fieldValue;
    int _original;

};


#endif //COUNTER_COUNTER_H
