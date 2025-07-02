#include "priority_queue.h"


void initQueue(PriorityQueue* pq, int capacity) {
    pq->capacity = capacity;
    pq->size = 0;
    pq->data = (int*)malloc(capacity * sizeof(int));
};

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
};

bool isFull(PriorityQueue* pq) {
    return pq->size == pq->capacity;
};

void enqueue(PriorityQueue* pq, int value) {
    if (isFull(pq)) {
        printf("Queue overflow!\n");
        return;
    }
    pq->data[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
};

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int root = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    heapifyDown(pq, 0);
    return root;
};

void printQueue(PriorityQueue* pq) {
    printf("Priority Queue:\n");;
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->data[i]);
    }
    printf("\n");
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
};

void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0 && pq->data[(index - 1) / 2] > pq->data[index]) {
        swap(&pq->data[index], &pq->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
};

void heapifyDown(PriorityQueue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->data[left] < pq->data[smallest]) smallest = left;
    if (right < pq->size && pq->data[right] < pq->data[smallest]) smallest = right;
    if (smallest != index) {
        swap(&pq->data[index], &pq->data[smallest]);
        heapifyDown(pq, smallest);
    }

};


