#include "circularQueue.h"


CircularQueue initQueue() {
    CircularQueue q;
    q.front = 0;
    q.rear = -1;
    q.count = 0;
    return q;
};

bool isEmpty(CircularQueue* queue) {
    return queue->count == 0;
};

bool isFull(CircularQueue* queue) {
    return queue->count == MAX_SIZE;
};

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    queue->count++;

    printf("Enqueued: %d\n", value);
};

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int value = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;

    printf("Dequeued: %d\n", value);
    return value;
};

void printQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue: ");
    int i = queue->front;
    for (int count = 0; count < queue->count; count++) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
};

