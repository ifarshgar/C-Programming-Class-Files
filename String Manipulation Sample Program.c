#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MaxSize 100

void bubbleSort(char [][MaxSize], int);
void printNames(const char [][MaxSize], int );
void countVowels(int, char [][MaxSize]);

/*int main() {
    printf("STRING FUNCTIONS\n");
    printf("-----------------------\n");

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

    bubbleSort(names, size);

    char results[size][MaxSize];   // holds final results

    for(int i=0; i<size; i++) {
        // finding the space in between of names
        int pos = strchr(names[i], ' ') - names[i];

        // recreating the names
        char firstPart[MaxSize/2];
        char secondPart[MaxSize/2];
        strncpy(firstPart, names[i], pos);
        strcpy(secondPart, (names[i])+pos+1);

        strcpy(results[i], secondPart);
        strcat(results[i], ", ");
        strcat(results[i], firstPart);
    }

    countVowels(size, results);

    printNames(results, size);

    return 0;
}*/

void countVowels(int size, char results[][MaxSize]) {
    char buffer[20];
    for(int i=0; i < size; i++) {
        int count = 0;
        for(int j=0; j<strlen(results[i]); j++) {
            char ch = tolower(results[i][j]);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                count++;
        }
        itoa(count, buffer, 10);
        strcat(results[i], " - ");
        strcat(results[i], buffer);
    }
}

void bubbleSort(char names[][MaxSize], int size) {// bubble sort
    for(int pass=1; pass<size; pass++) {
        for(int i=0; i<size-1; i++) {
            if(strcmp(names[i], names[i+1]) > 0) {
                // swapping values
                char temp[MaxSize];
                strcpy(temp, names[i]);
                strcpy(names[i], names[i+1]);
                strcpy(names[i+1], temp);
            }
        }
    }
}

void printNames(const char names[][MaxSize], int size) {
    for(int i=0; i<size; i++) {
        printf("#%d - %s\n", i+1, names[i]);
    }
}
