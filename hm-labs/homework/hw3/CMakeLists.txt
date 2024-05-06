cmake_minimum_required(VERSION 3.19)
project(hw3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(hw3
        dlinkedlist.c
        linkedlist.c
        list.h
        vector.c)
