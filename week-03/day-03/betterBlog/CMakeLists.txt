cmake_minimum_required(VERSION 3.14)
project(betterBlog)

set(CMAKE_CXX_STANDARD 14)

add_executable(betterBlog main.cpp BlogPost.cpp BlogPost.h Blog.cpp Blog.h)