#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct queue{
    int top;
    char values[MAX][100];
} myQueue;

void push(char *v)
{
    if(myQueue.top == MAX-1)
        printf("queue is full!\n\n");
    else
    {
        myQueue.top++;
        strcpy(myQueue.values[myQueue.top], v);
    }
}

char * pop()
{
    if(myQueue.top <= -1)
    {
        printf("queue is empty!\n\n");
        return "<empty>";
    }
    else
    {
        char *c = (char *) malloc(100*sizeof(char));
        strcpy(c, myQueue.values[0]);

        /*
           this implementation of the queue data structure is not very efficient
           due to the limitations that we have in simple arrays in C
           A better approach is to use linked-lists
           There is also another way, that is to use two pointers on the list. A head and a tail.
           As of right now I have just implemented a simple functioning queue.
        */
        for(int i=0; i<myQueue.top; i++) {
            strcpy(myQueue.values[i], myQueue.values[i+1]);
        }
        myQueue.top--;

        return c;
    }
}

int size() {
    return myQueue.top + 1;
}

void print()
{
    printf("Queue:\n");
    int i;
    for(i=0;i <= myQueue.top; i++)
    {
        printf("%d- %s\n", i+1, myQueue.values[i]);
    }
    printf("\n");
}

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























