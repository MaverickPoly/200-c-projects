#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DynamicList;

// Constructor
DynamicList* initDynamicList(size_t capacity);

// Special
void grow(DynamicList* list);
void shrink(DynamicList* list);

// Add Data
void append(DynamicList* list, int value);
int insert(DynamicList* list, int index, int value);

// Remove Data
int pop(DynamicList* list);
int removeAt(DynamicList* list, int index);

// Utils
bool contains(DynamicList* list, int value);
int get(DynamicList* list, int index);
void set(DynamicList* list, int index, int value);
size_t getSize(DynamicList* list);
bool isEmpty(DynamicList* list);
void clear(DynamicList* list);
void reverse(DynamicList* list);
void display(DynamicList* list);

// Destructure
void freeDynamicList(DynamicList* list);

#endif