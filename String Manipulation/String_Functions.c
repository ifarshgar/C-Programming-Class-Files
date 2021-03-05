//
// Created by Abdolrahman on 3/5/2021.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "String_Functions.h"

// This function takes a few names from the input and rearranges the first name and the last name differently.
void string_manipulation_test() {
    printf("... STRING FUNCTIONS Test ...\n\n");

    printf("Enter the number of people:\n> ");
    int size;
    scanf("%d", &size);

    // clearing the stdin after scanf
    char c;
    while ((c = getchar()) != '\n' && c != EOF);

    char buffer[MaxSize]; // buffer holder
    char names[size][MaxSize]; // holds entered names

    for(int i=0; i<size; i++) {
        printf("Enter #%d fullname:\n>", i+1);
        char *result = gets(buffer);
        strcpy(names[i], result);
    }

    char results[size][MaxSize];   // holds final results

    for(int i=0; i<size; i++) {
        // finding the space in between of names
        int pos = strchr(names[i], ' ') - names[i];

        // recreating the names
        char firstPart[MaxSize/2];
        char secondPart[MaxSize/2];
        strncpy(firstPart, names[i], pos);
        firstPart[pos] = '\0';
        strcpy(secondPart, (names[i])+pos+1);
        strcpy(results[i], secondPart);
        strcat(results[i], ", ");
        strcat(results[i], firstPart);
    }

    printNames(results, size);
}

void printNames(const char names[][MaxSize], int size) {
    for(int i=0; i<size; i++) {
        printf("#%d - %s\n", (i+1), names[i]);
    }
}

char * toLower(char *str) {
    int n = strlen(str);
    char *lower = (char *) malloc(n+1 * sizeof(char));

    for(int i=0; i<strlen(str); i++)
        lower[i] = tolower(str[i]);
    lower[n] = '\0';

    return lower;
}