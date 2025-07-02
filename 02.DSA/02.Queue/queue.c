#include "queue.h"


Queue CreateQueue() {
    Node* head = NULL;
    size_t size = 0;
    return (Queue){.head = head, .size = size};
}

void Enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = value;

    if (queue->size == 0) {
        queue->head = newNode;
    } else {
        Node* current = queue->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    queue->size++;
}

int Dequeue(Queue* queue) {
    const int returnValue = Peek(queue);

    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);

    return returnValue;
}

int Peek(Queue* queue) {
    if (queue->size == 0) exit(1);
    return queue->head->value;
}

bool IsEmpty(Queue* queue) {
    return queue->size == 0;
}

void Display(Queue* queue) {
    Node* current = queue->head;

    while (current != NULL) {
        printf("%d <- ", current->value);
        current = current->next;
    }
    printf("\n");
}

void Destroy(Queue* queue) {
    Node* current = queue->head;

    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
}
