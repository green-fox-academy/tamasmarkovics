cmake_minimum_required(VERSION 3.15)
project(extension)



# Change this to the name of the directory that contains your tests
set(PROJECT_TESTS_NAME MyApp_tests)

# Change this to the path where you extracted the Google Test files to
set(PATH_TO_GOOGLETEST "C:/googletest/googletest")

# Change this to your project name (optional)
set(PROJECT_NAME extension)


project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

# The next line creates an executable file from main.cpp with the same name as your project
add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(${PROJECT_TESTS_NAME})

# This line links your code to the main executable
target_link_libraries(${PROJECT_NAME})