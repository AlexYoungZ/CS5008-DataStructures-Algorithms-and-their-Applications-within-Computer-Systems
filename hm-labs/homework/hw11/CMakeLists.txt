cmake_minimum_required(VERSION 3.19)
project(hw11 C)

set(CMAKE_C_STANDARD 11)

add_executable(hw11 graph.h minheap.h dijkstra.h prim.h main.c)