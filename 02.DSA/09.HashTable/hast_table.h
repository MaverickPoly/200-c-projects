#ifndef HAST_TABLE_H
#define HAST_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 10


typedef struct {
    int value;
    int key;
} Element;

typedef struct {
    Element* elements;
    size_t size;
} Row;

typedef struct {
    Row* rows;
    size_t capacity;
} HashTable;

HashTable* init_hash_table(size_t capacity);
void insert(HashTable* table, int key, int value);
int delete(HashTable* table, int key);
int hashFunction(HashTable* table, int key);
bool contains_key(HashTable* table, int key);
void display(HashTable* table);
void destroy_table(HashTable* table);

#endif
