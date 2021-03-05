//
// Created by Abdolrahman on 3/5/2021.
//

#ifndef C_PROGRAMMING_STUDENT_INFO_H
#define C_PROGRAMMING_STUDENT_INFO_H

typedef struct StudentInfo StudentInfo;
struct StudentInfo{
    char studentNo[5];
    char name[10];
    int grade;
} *studentInfo;

#define STUDENT_INFO_FILE "StudentInfo.txt"

extern int studentInfoSize;
extern int studentInfoCapacity;

void initStudentInfo();
void extendStudentInfoCapacity();

int saveStudentInfo();
int loadStudentInfo();
void printStudentInfo();

#endif //C_PROGRAMMING_STUDENT_INFO_H
