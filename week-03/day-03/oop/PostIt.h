#ifndef OOP_POSTIT_H
#define OOP_POSTIT_H
#include <string>
using std::string;

class PostIt{
public:
    PostIt(string backgroundColor, string text, string textColor);
private:
    string _backgroundColor;
    string _text;
    string _textColor;
};


#endif //OOPs_POSTIT_H
