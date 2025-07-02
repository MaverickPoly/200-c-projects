#include "doublyLinkedList.h"


LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
};

void append(LinkedList* ll, int data) {
    if (isEmpty(ll)) {
        prepend(ll, data);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node* current = ll->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
};

void prepend(LinkedList* ll, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ll->head;
    newNode->prev = NULL;
    ll->head = newNode;
};

void insert(LinkedList* ll, int data, int index) {
    if (index + 1 >= size(ll) || isEmpty(ll)) {
            return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    int i = 0;
    Node* current = ll->head;
    while (i < index) {
        current = current->next;
        i++;
    }
    Node* prev = current->prev;
    current->prev = newNode;
    newNode->prev = prev;
    newNode->prev->next = newNode;
    newNode->next = current;
};

int pop(LinkedList* ll) {
    if (isEmpty(ll)) {
        printf("List is empty!\n");
        return -1;
    }
    Node* current = ll->head;
    if (size(ll) == 1) {
        deleteFirst(ll);
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    int returnVal = current->data;
    free(current);
    return returnVal;
};

void deleteFirst(LinkedList* ll) {
    if (size(ll) == 0) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = ll->head;
    ll->head->next->prev = NULL;
    ll->head = temp->next;
    free(temp);
};

// Remove item at specific index
void removeDL(LinkedList* ll, int index) {
    if (index >= size(ll) || isEmpty(ll) || index < 0) {
        printf("List is empty or index out of range!\n");
        return;
    }
    if (index == 0) {
        return deleteFirst(ll);
    }
    if (index == size(ll) - 1) {
        pop(ll);
        return;
    }

    Node* current = ll->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node* temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(temp);
};

void print(LinkedList* ll) {
    Node* current = ll->head;

    while (current != NULL) {
        printf("%d - ", current->data);
        current = current->next;
    }
    printf("\n");
};

size_t size(LinkedList* ll) {
    size_t i = 0;
    Node* current = ll->head;

    while (current != NULL) {
        current = current->next;
        i++;
    }
    return i;
};

bool contains(LinkedList* ll, int data) {
    Node* current = ll->head;
    while (current != NULL) {
        if (current->data == data) return true;
        current = current->next;
    }
    return false;
};

bool isEmpty(LinkedList* ll) {
    return size(ll) == 0;
};

void destroyLinkedList(LinkedList* ll) {
    Node* current = ll->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(ll);
};

