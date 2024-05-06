cmake_minimum_required(VERSION 3.19)
project(lab04_library C)

set(CMAKE_C_STANDARD 11)

add_executable(lab04_library
        hidden/secret.c
        hack.c
        lottery.c)
