#include <iostream>
#include "BlogPost.h"
#include "Blog.h"


int main()
{

    BlogPost firstBlog( "John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet", "2000.05.04.");
    BlogPost seecondBlog( "Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    BlogPost thirdBlog("I", "am", "fin done", "with this");
    Blog someBlogz;
    someBlogz.addBlogPost(firstBlog);
    someBlogz.addBlogPost(seecondBlog);
    someBlogz.addBlogPost(thirdBlog);
    someBlogz.update(2, firstBlog);
    someBlogz.update(2, firstBlog);
    someBlogz.update(2, firstBlog);
    someBlogz.deleteBlog(4);

    std::cout << someBlogz.sizeBlogs() << std::endl;


    return 0;
}