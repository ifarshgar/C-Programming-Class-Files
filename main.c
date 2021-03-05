//
// Created by Abdolrahman on 3/4/2021.
//
#include <stdio.h>

#include "FILE_IO/File_Read_Write_Example.h"

int main() {
    printf("*** C Programming ***\n");

    file_IO_with_fscanf_and_fprintf();
    file_IO_with_fread_and_fwrite();
    file_IO_with_fgets_and_fputs();

    return 0;
}