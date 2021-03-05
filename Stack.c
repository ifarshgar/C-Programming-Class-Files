#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Stack.h"

void stack_push(char *v) {
    if (myStack.top == MAX - 1)
        printf("Stack is full!\n");
    else {
        myStack.top++;
        strcpy(myStack.values[myStack.top], v);
    }
}

char * stack_pop() {
    if (myStack.top <= -1) {
        printf("Stack is empty!\n");
        return "<empty>";
    } else {
        char *c = (char *) malloc(100 * sizeof(char));
        strcpy(c, myStack.values[myStack.top]);
        myStack.top--;
        return c;
    }
}

int stack_size() {
    return myStack.top + 1;
}

void stack_print() {
    printf("Stack: ");
    int i;
    for (i = 0; i <= myStack.top; i++) {
        printf("%s ", myStack.values[i]);
    }
    printf("\n");
}
