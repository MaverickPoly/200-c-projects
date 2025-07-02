#include <stdio.h>

#include "priority_queue.h"


int main() {
    PriorityQueue pq;
    initQueue(&pq, 10);

    enqueue(&pq, 10);
    enqueue(&pq, 4);
    enqueue(&pq, 8);
    enqueue(&pq, 5);
    enqueue(&pq, 1);

    printQueue(&pq);
    printf("Dequeued: %d\n", dequeue(&pq));
    printf("Dequeued: %d\n", dequeue(&pq));

    printQueue(&pq);

    return 0;
}
