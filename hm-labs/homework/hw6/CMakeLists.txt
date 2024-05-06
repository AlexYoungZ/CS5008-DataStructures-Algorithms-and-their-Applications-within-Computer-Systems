cmake_minimum_required(VERSION 3.19)
project(hw6 C)

set(CMAKE_C_STANDARD 11)

add_executable(hw6 main.c deadlock.c racecondition.c diningPhilosopher.c)