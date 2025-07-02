#include <stdio.h>

#include "queue.h"


int main() {
    Queue q = CreateQueue();

    printf("Size: %llu\n", q.size);
    printf("Is Empty: %d\n", IsEmpty(&q));

    Display(&q);

    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);

    printf("\nSize: %llu\n", q.size);
    printf("Is Empty: %d\n", IsEmpty(&q));

    Display(&q);

    printf("\nPeek: %d\n", Peek(&q));
    printf("Deque: %d\n", Dequeue(&q));
    printf("Deque: %d\n", Dequeue(&q));
    printf("Deque: %d\n", Dequeue(&q));
    printf("Peek: %d\n", Peek(&q));

    Display(&q);
    Destroy(&q);

    // Everything works fine!!!!

    return 0;
}
