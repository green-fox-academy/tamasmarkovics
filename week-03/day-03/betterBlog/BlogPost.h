#ifndef OOP_BLOGPOST_H
#define OOP_BLOGPOST_H

#include <string>
using std::string;

class BlogPost {
public:
    BlogPost(string authorName, string title, string text, string publicationDate);
private:
    string _authorName;
    string _title;
    string _text;
    string _publicationDate;

};


#endif //OOP_BLOGPOST_H