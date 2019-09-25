#include <iostream>
#include "PostIt.h"
#include "BlogPost.h"

int main()
{
    PostIt first("orange", "Idea 1", "blue");
    PostIt second("pink", "Awesome", "black");
    PostIt third("yellow", "Super B", "green");

    BlogPost firstBlog( "John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet", "2000.05.04.");
    BlogPost seecondBlog( "Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    BlogPost thirdBlog("I", "am", "fin done", "with this");



    return 0;
}