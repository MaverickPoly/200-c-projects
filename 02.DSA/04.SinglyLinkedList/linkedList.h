#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int value;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    size_t size;
} LinkedList;

LinkedList createLinkedList();
void append(LinkedList *ll, int value); // Add item to the end
void prepend(LinkedList *ll, int value); // Add item to the start
size_t getSize(const LinkedList *ll); // Get the size
int removeLL(LinkedList *ll, const int value); // Remove Node with value if found
int pop(LinkedList* ll); // Return the value of the last element and delete it
bool isEmpty(const LinkedList *ll);
bool contains(const LinkedList *ll, int value);
void print(const LinkedList* ll);
void destroyLinkedList(const LinkedList* ll); // Free up the memory


#endif
