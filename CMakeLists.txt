cmake_minimum_required(VERSION 3.29)
project(Mastering_C C)

set(CMAKE_C_STANDARD 23)

add_executable(Mastering_C main.c
        Queue.c
        GenericQueueDataStructure.c
        LinkedList.c)
