#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

#define FILENAME "list_of_people"

int main()
{
    printf("Working with Files in C - fread & fwrite \n\n");

    // an array of two instances of the Person struct
    P[0].id = 1;
    P[0].firstName = "Aley";
    P[0].lastName = "A";
    P[0].city = "Eskişehir";

    P[1].id = 2;
    P[1].firstName = "Eve";
    P[1].lastName = "E";
    P[1].city = "Istanbul";

    print(P[0]);
    print(P[1]);

    // writing the struct data into the file - saving
    save(FILENAME);

    // reopening the file to read the data back
    load(FILENAME);

    printf("\nTrying to get the first element with random access to the file: \n");
    getPerson(FILENAME, 0);

    printf("\nTrying to get the second element with random access to the file: \n");
    getPerson(FILENAME, 1);

    printf("\nTrying to get the an element which does not exist: \n");
    getPerson(FILENAME, 2);


    printf("\nThe End!\n");
    return 0;
}
