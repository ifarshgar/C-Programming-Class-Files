cmake_minimum_required(VERSION 3.15)
project(C_Programming C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Programming_Files
        main.c
        "Common Structures/Queue.h" "Common Structures/Queue.c"
        "Common Structures/Stack.h" "Common Structures/Stack.c"
        FILE_IO/File_Read_Write_Example.h FILE_IO/File_Read_Write_Example.c
        FILE_IO/Person.h FILE_IO/Person.c
        FILE_IO/StudentInfo.c FILE_IO/StudentInfo.h
        "String Manipulation/String_Functions.h" "String Manipulation/String_Functions.c"
        )
