#include <stdio.h>

#include "circularQueue.h"


int main() {
    CircularQueue q = initQueue();

    printf("Is Empty: %d\n", isEmpty(&q));
    printf("Is Full: %d\n", isFull(&q));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Is Empty: %d\n", isEmpty(&q));
    printf("Is Full: %d\n", isFull(&q));

    printQueue(&q);

    dequeue(&q);
    dequeue(&q);

    printQueue(&q);

    enqueue(&q, 100);
    enqueue(&q, 120);

    printQueue(&q);

    // circular queue implemented!!!!

    return 0;
}
