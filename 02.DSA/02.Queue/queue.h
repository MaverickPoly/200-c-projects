#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int value;
    struct Node* next;
} Node;


typedef struct {
    Node* head;
    size_t size;
} Queue;


Queue CreateQueue();
void Enqueue(Queue* queue, int value);
int Dequeue(Queue* queue);
int Peek(Queue* queue);
bool IsEmpty(Queue* queue);
void Display(Queue* queue);
void Destroy(Queue* queue);

#endif
