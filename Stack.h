//
// Created by Abdolrahman on 3/4/2021.
//

#ifndef C_PROGRAMMING_FILE_STACK_H
#define C_PROGRAMMING_FILE_STACK_H

#define MAX 100

struct stack {
    int top;
    char values[MAX][100];
} myStack;

void stack_push(char *v);
char * stack_pop();
int stack_size();
void stack_print();

#endif //C_PROGRAMMING_FILE_STACK_H