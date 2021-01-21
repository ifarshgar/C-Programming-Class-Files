#include <stdio.h>

struct Queue {
    int item;
    struct Queue* next;
};

int main() {
    printf("Hello, World!\n");

    struct Queue queue;
    queue.item = 11111;
    queue.next = NULL;

    struct Queue queue2;
    queue2.item = 22222;
    queue.next = &queue2;

    struct Queue queue3;
    queue3.item = 33333;
    queue2.next = &queue3;

    // create loop!
    queue3.next = &queue;

    struct Queue *q = &queue;
    for(int i=1; i<10; i++) {
        printf("%i - %d\n", i, q->item);
        q = q->next;
    }


    return 0;
}
