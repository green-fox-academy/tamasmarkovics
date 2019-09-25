#include "Counter.h"

Counter::Counter()
{
    _fieldValue = 0;
    _original = 0;
}

Counter::Counter(int fieldValue)
{
    _fieldValue = fieldValue;
    _original = fieldValue;
}

void Counter::add(int number)
{
    _fieldValue += number;
}

void Counter::add()
{
    _fieldValue++;
}

void Counter::reset()
{
    _fieldValue = _original;
}

int Counter::get()
{
    return _fieldValue;
}
