#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

void queue_push(char *v) {
    if (myQueue.top == MAX - 1)
        printf("queue is full!\n\n");
    else {
        myQueue.top++;
        strcpy(myQueue.values[myQueue.top], v);
    }
}

char * queue_pop() {
    if (myQueue.top <= -1) {
        printf("queue is empty!\n\n");
        return "<empty>";
    } else {
        char *c = (char *) malloc(100 * sizeof(char));
        strcpy(c, myQueue.values[0]);

        for (int i = 0; i < myQueue.top; i++) {
            strcpy(myQueue.values[i], myQueue.values[i + 1]);
        }
        myQueue.top--;

        return c;
    }
}

int queue_size() {
    return myQueue.top + 1;
}

void queue_print() {
    printf("Queue:\n");
    int i;
    for (i = 0; i <= myQueue.top; i++) {
        printf("%d- %s\n", i + 1, myQueue.values[i]);
    }
    printf("\n");
}

/*
int main()
{
    myQueue.top = -1;
    char str[100];
    char *t;
    char junk;

    int ch = -1;
    while(ch != 0) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print All\n");
        printf("0. Exit\n");
        printf("> ");

        scanf("%d", &ch);

        switch(ch) {
        case 1:
            printf("Enter string: ");
            scanf("%c%100[^\n]", &junk, str);
            push(str);
            printf("\n");
            break;
        case 2:
            t = pop();
            if(strcmp(t, "<empty>") != 0) {
                printf("poped: %s\n\n", t);
            }
            break;
        case 3:
            if(myQueue.top == -1) {
                printf("The queue is empty!\n\n");
            } else {
                print();
            }
            break;
        case 0:
            printf("Exit...\n");
            break;
        default:
            printf("Wrong input!\n\n");
            break;
        }
    }

    return 0;
}
*/