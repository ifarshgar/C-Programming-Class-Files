//
// Created by Abdolrahman on 3/4/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "File_Read_Write_Example.h"
#include "Person.h"
#include "StudentInfo.h"

void file_IO_with_fscanf_and_fprintf() {
    printf("\n... File Input/Output with fscanf and fprintf Test ...\n");

    // opening a file for writing
    const char *FILENAME = "MyData.txt";
    FILE *output = fopen(FILENAME, "w");
    if(output == NULL) {
        printf("Unable to create the file '%s'", FILENAME);
        exit(1);
    }

    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    char text[10][20] = {"one","two","three","four","five","six","seven","eight","nine","ten"};

    // writing data to file
    for(int i=0; i<10; i++) {
        fprintf(output, "%d %s\n", a[i], text[i]);
        printf("%d %s\n", a[i], text[i]);
    }
    // closing the file after writing is finished.
    fclose(output);
    printf("Data saved successfully!\n");

    // reopening the file. This time in reading mode.
    FILE *input = fopen(FILENAME, "r");
    if(input == NULL ) {
        printf("'%s' file not found!", FILENAME);
        exit(1);
    }

    // reading data from the file
    int b[10];
    char str[10][20];
    int index = 0;
    while(fscanf(input, "%d %100[^\n]", &b[index], str[index]) != EOF) {
        printf("%d %s \n", b[index], str[index]);
        index++;
    }
    fclose(input);
    printf("Data retrieved successfully!\n");
}

void file_IO_with_fread_and_fwrite() {
    printf("\n... File Input/Output with fread and fwrite Test ...\n");

    const char* FILENAME = "MyData.dat";

    // an array of two instances of the Person struct
    person = (Person *) malloc(2 * sizeof(Person));
    person[0].id = 1;
    person[0].firstName = "Aley";
    person[0].lastName = "A";
    person[0].city = "Eskişehir";

    person[1].id = 2;
    person[1].firstName = "Eve";
    person[1].lastName = "E";
    person[1].city = "Istanbul";

    // printing the values of newly created instances of the Person struct.
    printPerson(&person[0]);
    printPerson(&person[1]);

    // writing the struct data into the file - saving
    savePerson(FILENAME, person, 2);

    // saving another Person
    Person pp;
    pp.id = 3;
    pp.firstName = "Leo";
    pp.lastName = "Lee";
    pp.city = "Kyrenia";
    savePerson(FILENAME, &pp, 1);

    // retrieving the struct data from the file - loading
    Person *p = loadPerson(FILENAME, 3);
    printPerson(&p[0]);
    printPerson(&p[1]);
    printPerson(&p[2]);

    printf("\nTrying to get the first element with random access to the file: \n");
    Person *pq = getPerson(FILENAME, 0);
    printPerson(pq);

    printf("\nTrying to get the second element with random access to the file: \n");
    Person *q = getPerson(FILENAME, 1);
    printPerson(q);

    printf("\nTrying to get the an element which does not exist: \n");
    Person *r = getPerson(FILENAME, 90);
    printPerson(r);
}

void file_IO_with_fgets_and_fputs() {
    printf("\n... File Input/Output with fgets and fputs Test ...\n");

    initStudentInfo();
    // first student
    strcpy(studentInfo[0].studentNo, "1111");
    strcpy(studentInfo[0].name, "Aley");
    studentInfo[0].grade = 95;
    studentInfoSize++; // increasing the number of elements (size). Crucial to the save and load functions.
    // second student
    strcpy(studentInfo[1].studentNo, "2222");
    strcpy(studentInfo[1].name, "Eve");
    studentInfo[1].grade = 95;
    studentInfoSize++;
    // third student
    strcpy(studentInfo[2].studentNo, "3333");
    strcpy(studentInfo[2].name, "Quin");
    studentInfo[2].grade = 95;
    studentInfoSize++;

    // printing the values of newly created instances of the Person struct.
    printStudentInfo(&studentInfo[0]);
    printStudentInfo(&studentInfo[1]);
    printStudentInfo(&studentInfo[2]);

    // writing the struct data into the file - saving
    int size = saveStudentInfo();
    if(size == 3)
        printf("Data saved successfully!\n\n");

    // retrieving the struct data from the file - loading
    studentInfoSize = 0; // setting the number of elements to zero again.
    size = loadStudentInfo();
    printStudentInfo(&studentInfo[0]);
    printStudentInfo(&studentInfo[1]);
    printStudentInfo(&studentInfo[2]);
    if(size == 3)
        printf("Data retrieved successfully!\n\n");
}