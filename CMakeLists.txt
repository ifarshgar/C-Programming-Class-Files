cmake_minimum_required(VERSION 3.15)
project(C_Programming_Files C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_Programming_Files
        FileIO.c
        IO.c
        linear_and_binary_search.c
        main.c
        "Queue - Linked List.c"
        Queue.c
        Stack.c
        "String Manipulation Sample Program.c"
        structures.c
        structures.h
        "Two Dimensional Dynamic Array.c")
