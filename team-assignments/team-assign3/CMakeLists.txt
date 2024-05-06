cmake_minimum_required(VERSION 3.19)
project(team_assign3 C)

set(CMAKE_C_STANDARD 11)

include_directories(siyangzhang)

add_executable(team_assign3
        siyangzhang/dlinkedlist.c
        siyangzhang/linkedlist.c
        siyangzhang/queue.h
        siyangzhang/sllqueue.c
        siyangzhang/sllstack.c
        siyangzhang/stack.h
        siyangzhang/vector.c
        siyangzhang/vqueue.c
        siyangzhang/vstack.c)
