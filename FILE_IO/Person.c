#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

void save(const char *fileName, Person *p, int size) {
    // opening a file for writing in write mode
    FILE *fp = fopen(fileName, "a");
    if(fp == NULL) {
        char msg[100] = "Unable to create the file";
        strcat(msg, fileName);
        strcat(msg, "\n");
        printf("%s", msg);
        exit(1);
    }

    // writing the data array to the file using fwrite method
    fwrite(p, sizeof(Person), size, fp);
    // close the file after writing
    fclose(fp);
    printf("Data saved successfully!\n\n");
}

Person * load(const char *fileName, int size) {
    FILE *input = fopen(fileName, "r");
    if( input == NULL ) {
        char msg[100] = "File ";
        strcat(msg, fileName);
        strcat(msg, " not found!\n");
        printf("%s", msg);
        exit(1);
    }

    // reading data from the file
    Person *p = (Person *) malloc(size * sizeof(Person));
    fread(p, sizeof(Person), size, input);
    fclose(input);
    printf("Data loaded successfully!\n");

    return p;
}

void printPerson(Person *p) {
    if(p != NULL) {
        char *format = "ID: %d\n"
                       "First name: %s\n"
                       "Last name: %s\n"
                       "City: %s\n"
                       "-----------------------\n";

        printf(format, p->id, p->firstName, p->lastName, p->city);
    }
}

Person * getPerson(const char *fileName, int index) {
    FILE *input = fopen(fileName, "r");
    if( input == NULL ) {
        char msg[100] = "File ";
        strcat(msg, fileName);
        strcat(msg, " not found!\n");
        printf("%s", msg);
        exit(1);
    }

    // gets the elements from the end of the file
    if(index < 0) {
        fseek(input, index * (sizeof(Person)), SEEK_END);
    }

    // gets the elements from the beginning of the file
    else {
        fseek(input, index*(sizeof(Person)), SEEK_SET);
    }

    Person *p = (Person *) malloc(sizeof(Person));
    if (fread(p, sizeof(Person), 1, input) == 1) {
        fclose(input);
        return p;
    } else {
        printf("Data not found!\n");
        fclose(input);
        return NULL;
    }
}
