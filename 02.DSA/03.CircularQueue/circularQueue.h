#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    size_t count;
} CircularQueue;

CircularQueue initQueue();
bool isEmpty(CircularQueue* queue);
bool isFull(CircularQueue* queue);
void enqueue(CircularQueue* queue, int value);
int dequeue(CircularQueue* queue);
void printQueue(CircularQueue* queue);


#endif