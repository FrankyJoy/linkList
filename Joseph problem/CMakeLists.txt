cmake_minimum_required(VERSION 3.7)
project(circular_linked_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES withlist.cpp withqueue.cpp withlinklist.cpp)
add_executable(circular_linked_list ${SOURCE_FILES})