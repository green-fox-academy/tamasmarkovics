#ifndef BETTERBLOG_BLOG_H
#define BETTERBLOG_BLOG_H
#include "BlogPost.h"
#include <vector>
using std::vector;

class Blog {
public:
    void deleteBlog(int index);
    void update(int index, BlogPost &blogPost);
    void addBlogPost(BlogPost &blogPost);
    int sizeBlogs();
private:
    vector<BlogPost> _blogs;

};


#endif //BETTERBLOG_BLOG_H
