#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    struct Node* next;
} Node;


typedef struct {
    Node* top;
    size_t size;
} Stack;

Stack CreateStack();
void Push(Stack* stack, int value);
int Pop(Stack* stack);
int Peek(Stack* stack);
bool IsEmpty(Stack* stack);
void Display(const Stack stack);
void DestroyStack(Stack* stack);

#endif
