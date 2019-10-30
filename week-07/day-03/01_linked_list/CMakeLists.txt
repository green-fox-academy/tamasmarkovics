cmake_minimum_required(VERSION 3.15)
project(01_linked_list C)

set(CMAKE_C_STANDARD 99)

add_executable(01_linked_list main.c linked_list.c linked_list.h)