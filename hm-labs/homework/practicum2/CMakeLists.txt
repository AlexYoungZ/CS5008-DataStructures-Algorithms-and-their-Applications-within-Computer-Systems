cmake_minimum_required(VERSION 3.19)
project(practicum2 C)

set(CMAKE_C_STANDARD 11)

add_executable(practicum2 floydWarshallNonRecursive.h floydWarshallRecursive.h main.c)