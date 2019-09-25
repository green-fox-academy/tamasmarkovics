cmake_minimum_required(VERSION 3.14)
project(fleetOfThings)

set(CMAKE_CXX_STANDARD 14)

add_executable(fleetOfThings main.cpp Thing.cpp Thing.h Fleet.cpp Fleet.h)