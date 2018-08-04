cmake_minimum_required(VERSION 3.10)
project(string_tests)

set(CMAKE_CXX_STANDARD 11)

add_executable(tests tests/main.cpp string.h)