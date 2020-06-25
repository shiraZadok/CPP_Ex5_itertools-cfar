cmake_minimum_required(VERSION 3.15)
project(cppEx5_iterTools)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppEx5_iterTools Demo.cpp range.hpp accumulate.hpp filterfalse.hpp compress.hpp Test.cpp)