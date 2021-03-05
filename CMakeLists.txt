cmake_minimum_required(VERSION 3.15)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Programming_Files
        main.c
        Queue.h Queue.c
        Stack.h Stack.c
        "String Manipulation Sample Program.c"
        FILE_IO/File_Read_Write_Example.h FILE_IO/File_Read_Write_Example.c
        FILE_IO/Person.h FILE_IO/Person.c
        )
