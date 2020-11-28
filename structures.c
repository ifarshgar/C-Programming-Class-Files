#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void save(const char *fileName) {
    // opening a file for writing
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL) {
        char msg[100] = "Unable to create the file";
        strcat(msg, fileName);
        strcat(msg, "\n");
        printf(msg);
        exit(1);
    }

    // writing data to the file using fwrite method
    for(int i=0; i<2; i++) {
        fwrite(&P[i], sizeof(Person), 1, fp);
    }

    // close the file after writing
    fclose(fp);

    printf("Data saved successfully!\n\n");
}

void load(const char *fileName) {
    FILE *input = fopen(fileName, "r");
    if( input == NULL ) {
        char msg[100] = "File ";
        strcat(msg, fileName);
        strcat(msg, " not found!\n");
        printf(msg);
        exit(1);
    }

    // reading data from the file
    int i = 0;
    while( fread(&P[i], sizeof(Person), 1, input) == 1) {
        print(P[i]);
    }

    fclose(input);
    printf("Data loaded successfully!\n\n");
}

void print(const Person p) {
    char *format = "ID: %d\n"
           "First name: %s\n"
           "Last name: %s\n"
           "City: %s\n"
           "-----------------------\n";

    printf(format, p.id, p.firstName, p.lastName, p.city);
}

void getPerson(const char *fileName, int index) {
    FILE *input = fopen(fileName, "r");
    if( input == NULL ) {
        char msg[100] = "File ";
        strcat(msg, fileName);
        strcat(msg, " not found!\n");
        printf(msg);
        exit(1);
    }

    // gets the elements from the end
    if(index < 0) {
        fseek(input, index * (sizeof(Person)), SEEK_END);
    }

    // gets the elements counting from the beginning of the file
    else {
        fseek(input, index*(sizeof(Person)), SEEK_SET);
    }

    Person p;
    if (fread(&p, sizeof(Person), 1, input) == 1) {
        print(p);
    } else {
        printf("The data not found!\n");
    }
}
