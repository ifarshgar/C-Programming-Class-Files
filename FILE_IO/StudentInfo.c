//
// Created by Abdolrahman on 3/5/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StudentInfo.h"

int studentInfoSize = 0;
int studentInfoCapacity = 0;

// initializing the array of structs for the first time
void initStudentInfo() {
    studentInfoCapacity = 100;
    studentInfo = (StudentInfo *) malloc(studentInfoCapacity * sizeof(StudentInfo));
}

// extending the size of the array if its necessary
void extendStudentInfoCapacity() {
    StudentInfo *temp = (StudentInfo *) malloc(studentInfoSize * sizeof(StudentInfo));
    for(int i=0; i<studentInfoSize; i++) {
        strcpy(temp[i].name, studentInfo[i].name);
        strcpy(temp[i].studentNo, studentInfo[i].studentNo);
        temp[i].grade = studentInfo[i].grade;
    }

    studentInfoCapacity = studentInfoSize * 2;
    studentInfo = (StudentInfo *) malloc(studentInfoCapacity * sizeof(StudentInfo));
    for(int i=0; i<studentInfoSize; i++) {
        strcpy(studentInfo[i].name, temp[i].name);
        strcpy(studentInfo[i].studentNo, temp[i].studentNo);
        studentInfo[i].grade = temp[i].grade;
    }
}

int loadStudentInfo() {
    if(studentInfoCapacity == 0) {
        initStudentInfo();
    }

    FILE *stud_file = fopen(STUDENT_INFO_FILE,"r");
    if(stud_file == NULL) {
        printf("'%s' file not found!\n", STUDENT_INFO_FILE);
        exit(1);
    }

    int index = 0;
    char line[100];
    while(fgets(line, 100, stud_file) != NULL) {
        if(strcmp(line, "\n") == 0)
            continue;

        char *token = strtok(line, " ");
        strcpy(studentInfo[index].studentNo, token);
        token = strtok(NULL, " ");
        strcpy(studentInfo[index].name, token);
        token = strtok(NULL, " ");
        studentInfo[index].grade = atoi(token);

        studentInfoSize++;
        index++;
        if(index == studentInfoCapacity) {
            extendStudentInfoCapacity();
        }
    }
    fclose(stud_file);
    return studentInfoSize;
}

int saveStudentInfo() {
    FILE *stud_file = fopen(STUDENT_INFO_FILE,"w");
    if(stud_file == NULL) {
        printf("'%s' file not found!\n", STUDENT_INFO_FILE);
        exit(1);
    }

    int index = 0;
    char line[100];
    for(int i=0; i<studentInfoSize; i++) {
        strcpy(line, studentInfo[i].studentNo);
        strcat(line, " ");
        strcat(line, studentInfo[i].name);
        strcat(line, " ");
        char buffer[64];
        itoa(studentInfo[i].grade, buffer, 10);
        strcat(line, buffer);
        strcat(line, "\n");
        fputs(line, stud_file);
        index++;
    }
    fclose(stud_file);
    return index;
}

void printStudentInfo(StudentInfo *si) {
    if(si != NULL) {
        char *format = "StudentNo: %s\n"
                       "Name: %s\n"
                       "Grade: %d\n"
                       "-----------------------\n";

        printf(format, si->studentNo, si->name, si->grade);
    }
}