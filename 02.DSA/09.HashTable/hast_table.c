#include "hast_table.h"


HashTable* init_hash_table(size_t capacity) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->capacity = capacity;
    table->rows = (Row*)malloc(sizeof(Row) * capacity);
    for (int i = 0; i < capacity; i++) {
        table->rows[i].size = 0;
        table->rows[i].elements = (Element*)malloc(sizeof(Element) * CAPACITY);
    }
    return table;
}


void insert(HashTable* table, int key, int value) {
    int hashKey = hashFunction(table, key);
    Row* row = &(table->rows[hashKey]);

    if (row->size == CAPACITY) {
        printf("Row is full!\n");
        return;
    }
    Element element = (Element){.key = key, .value = value};
    row->elements[row->size++] = element;
}


int delete(HashTable* table, int key) {
    int hashKey = hashFunction(table, key);
    Row* row = &(table->rows[hashKey]);

    if (row->size == 0) {
        return 0;
    }

    for (int i = 0; i < row->size; i++) {
        if (row->elements[i].key == key) {
            for (int j = i; j < row->size - 1; j++) {
                row->elements[j] = row->elements[j + 1];
            }
            row->size--;
            return 1;
        }
    }

    return 0;
}

int hashFunction(HashTable* table, int key) {
    return key % table->capacity;
}

bool contains_key(HashTable* table, int key) {
    int hashKey = hashFunction(table, key);
    Row *row = &(table->rows[hashKey]);
    for (int i = 0; i < row->size; i++) {
        Element element = row->elements[i];
        if (element.key == key) return true;
    }
    return false;
}

void display(HashTable* table) {
    for (int i = 0; i < table->capacity; i++) {
        Row row = table->rows[i];
        printf("Row %d: ", i);
        printf("{");
        for (int j = 0; j < row.size; j++) {
            printf("%d: %d  ", row.elements[j].key, row.elements[j].value);
        }
        printf("}\n");
    }
}


void destroy_table(HashTable* table) {
    for (int i = 0; i < table->capacity; i++) {
        free(table->rows[i].elements);
    }
    free(table->rows);
    free(table);
}

