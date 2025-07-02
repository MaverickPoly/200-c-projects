#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int *data;
    int capacity;
    int size;
} PriorityQueue;

void initQueue(PriorityQueue* pq, int capacity);
bool isEmpty(PriorityQueue* pq);
bool isFull(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, int value);
int dequeue(PriorityQueue* pq);
void printQueue(PriorityQueue* pq);
void swap(int *a, int *b);
void heapifyUp(PriorityQueue* pq, int index);
void heapifyDown(PriorityQueue* pq, int index);


#endif
