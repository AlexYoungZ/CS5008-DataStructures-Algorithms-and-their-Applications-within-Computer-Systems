cmake_minimum_required(VERSION 3.19)
project(siyangzhang C)

set(CMAKE_C_STANDARD 11)

add_executable(siyangzhang
        dlinkedlist.c
        linkedlist.c
        vector.c
        sllqueue.c
        sllstack.c
        vqueue.c
        vstack.c
        )
