#include "dynamic_list.h"


// Constructor
DynamicList* initDynamicList(size_t capacity) {
    DynamicList* list = (DynamicList*)malloc(sizeof(DynamicList));
    list->size = 0;
    list->capacity = capacity;
    list->data = (int*)malloc(list->capacity * sizeof(int));
    return list;
};


// Special
void grow(DynamicList* list) {
    list->capacity *= 2;
    list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
};

void shrink(DynamicList* list) {
    list->capacity /= 2;
    list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
};


// Add Data
void append(DynamicList* list, int value) {
    list->data[list->size++] = value;
    if (list->size == list->capacity) {
        grow(list);
    }
};

int insert(DynamicList* list, int index, int value) {
    if (index < 0 || index > list->size) return -1;

    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->size++;

    if (list->size == list->capacity) {
        grow(list);
    }
    return 1;
};


// Remove Data
int pop(DynamicList* list) {
    int value = list->data[--list->size];

    if (list->size + 1 < list->capacity / 2) {
        shrink(list);
    }
    return value;
};

int removeAt(DynamicList* list, int index) {
    if (index < 0 || index >= list->size) return -1;
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    if (list->size - 1 < list->capacity / 2) {
        shrink(list);
    }
    return 1;
};


// Utils
bool contains(DynamicList* list, int value) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == value) return true;
    }
    return false;
};

int get(DynamicList* list, int index) {
    if (index < 0 || index >= list->size) return -1;
    return list->data[index];
};

void set(DynamicList* list, int index, int value) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds!\n");
        exit(-1);
    }
    list->data[index] = value;
};

size_t getSize(DynamicList* list) {
    return list->size;
};

bool isEmpty(DynamicList* list) {
    return list->size == 0;
};

void clear(DynamicList* list) {
    list->size = 0;
    shrink(list);
};

void reverse(DynamicList* list) {
    size_t start = 0;
    size_t end = list->size - 1;
    while (start < end) {
        const int temp = list->data[start];
        list->data[start] = list->data[end];
        list->data[end] = temp;
        start++;
        end--;
    }
};

void display(DynamicList* list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        printf("%d  ", list->data[i]);
    }
    printf("]\n");
};


// Destructure
void freeDynamicList(DynamicList* list) {
    free(list->data);
    free(list);
};
