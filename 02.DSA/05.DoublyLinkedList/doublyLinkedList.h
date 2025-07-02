#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct {
    struct Node* head;
} LinkedList;

typedef struct Node Node;

LinkedList* createLinkedList();
void append(LinkedList* ll, int data);
void prepend(LinkedList* ll, int data);
void insert(LinkedList* ll, int data, int index);
int pop(LinkedList* ll);
void deleteFirst(LinkedList* ll);
void removeDL(LinkedList* ll, int index);
void print(LinkedList* ll);
size_t size(LinkedList* ll);
bool contains(LinkedList* ll, int data);
bool isEmpty(LinkedList* ll);
void destroyLinkedList(LinkedList* ll);


#endif
