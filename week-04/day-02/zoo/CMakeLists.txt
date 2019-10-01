cmake_minimum_required(VERSION 3.15)
project(zoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(zoo main.cpp Animals.cpp Animals.h eggLayers.cpp eggLayers.h LiveBearer.cpp LiveBearer.h Mammals.cpp Mammals.h)