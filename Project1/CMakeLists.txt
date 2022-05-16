cmake_minimum_required(VERSION 3.21)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 proj1-person.hpp proj1-main.cpp proj1-person.cpp)
