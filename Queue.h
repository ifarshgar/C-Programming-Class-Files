//
// Created by Abdolrahman on 3/4/2021.
//

#ifndef C_PROGRAMMING_FILE_QUEUE_H
#define C_PROGRAMMING_FILE_QUEUE_H

#define MAX 100

struct queue{
    int top;
    char values[MAX][100];
} myQueue;

void queue_push(char *v);
char * queue_pop();
int queue_size();
void queue_print();

#endif //C_PROGRAMMING_FILE_QUEUE_H