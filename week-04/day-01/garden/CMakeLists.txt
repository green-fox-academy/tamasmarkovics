cmake_minimum_required(VERSION 3.15)
project(garden)

set(CMAKE_CXX_STANDARD 14)

add_executable(garden main.cpp Plant.cpp Plant.h Flower.cpp Flower.h Tree.cpp Tree.h Garden.cpp Garden.h)