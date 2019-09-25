#include "SharpieSet.h"



int SharpieSet::countUsable()
{
    int counter = 0;
    for (int i = 0; i < _listOfSharpies.size(); i++){
        if (_listOfSharpies[i].getInkAmount() > 0){
            counter++;
        }
    }
    return counter;
}
void SharpieSet::removeTrash()
{   int counter = 0;
    for (int i = 0; i < _listOfSharpies.size();){
        if (_listOfSharpies[i].getInkAmount() == 0){
            _listOfSharpies.erase(_listOfSharpies.begin() + i);
            counter++;
        } else i++;
    }
    std::cout << counter << " sharpies got removed cause they were empty!" << std::endl;
}


void SharpieSet::addSharpie(Sharpie &sharpie){
    _listOfSharpies.push_back(sharpie);
}

Sharpie* SharpieSet::getSharpie(int index){
    return &_listOfSharpies[index];
}