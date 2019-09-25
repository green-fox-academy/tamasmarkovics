cmake_minimum_required(VERSION 3.14)
project(farmAnimals)

set(CMAKE_CXX_STANDARD 14)

add_executable(farmAnimals main.cpp Animals.cpp Animals.h Farm.cpp Farm.h)