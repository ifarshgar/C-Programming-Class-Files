#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct stack{
    int top;
    char values[MAX];
} myStack;

void push(char v)
{
    if(myStack.top == MAX-1)
        printf("Stack is full!\n");
    else
    {
        myStack.top++;
        myStack.values[myStack.top]=v;
    }
}

char pop()
{
    if(myStack.top <= -1)
    {
        printf("Stack is empty!\n");
        return NULL;
    }
    else
    {
        char c = myStack.values[myStack.top];
        myStack.top--;
        return c;
    }
}

int size() {
    return myStack.top + 1;
}

void print()
{
    printf("Stack: ");
    int i;
    for(i=0;i <= myStack.top; i++)
    {
        printf("%c ", myStack.values[i]);
    }
    printf("\n");
}

int main()
{
    myStack.top = -1;
    char str[500];

    while(strcmp(str, "exit") != 0) {
        printf("Enter string: ");
        gets(str);

        int i,j;
        for(i=0; str[i] != '\0'; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                push(str[i]);
            }
            else if(str[i]>= '0' && str[i]<='9')
            {
                int pos = str[i] - '0';
                for(j=0;j<pos;j++)
                {
                    char c = pop();
                    if( c != NULL)
                        printf("Popped: %c\n",c);
                }
            }
            else if(str[i] == '$')
            {
                printf("size: %d\n", size());
                print();
            }
            else
                continue;
        }
    }

    return 0;
}
