#include "Blog.h"

void Blog::deleteBlog(int index)
{
    _blogs.erase(_blogs.begin() + index);
}


void Blog::update(int index, BlogPost &blogPost)
{
    _blogs.insert(_blogs.begin()+index, blogPost);
}

void Blog::addBlogPost(BlogPost &blogPost)
{
    _blogs.push_back(blogPost);
}

int Blog::sizeBlogs()
{
    return _blogs.size();
}