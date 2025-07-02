#include "linkedList.h"

typedef struct Node Node;

LinkedList createLinkedList() {
    LinkedList ll;
    ll.head = NULL;
    ll.size = 0;
    return ll;
};

void append(LinkedList *ll, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(ll)) {
        ll->head = newNode;
    } else {
        Node* current = ll->head;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    ll->size++;
};

void prepend(LinkedList *ll, const int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = ll->head;
    ll->head = newNode;
    ll->size++;
};

size_t getSize(const LinkedList *ll) {
    return ll->size;
};

int removeLL(LinkedList *ll, const int value) {
    if (isEmpty(ll)) {
        printf("Linked List is Empty!\n");
        return 0;
    }

    Node* current = ll->head;
    Node* prev = NULL;

    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in a list!\n", value);
        return 0;
    }

    if (prev == NULL) { // Removing the head of list
        ll->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    ll->size--;
    return 1;
};

int pop(LinkedList* ll) {
    if (isEmpty(ll)) {
        printf("Linked List is Empty!\n");
        return -1;
    }
    if (getSize(ll) == 1) {
        const int val = ll->head->value;
        free(ll->head);
        ll->size--;
        return val;
    } else {
        Node* current = ll->head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        const int val = current->next->value;
        free(current->next);
        current->next = NULL;
        ll->size--;
        return val;
    }
};

bool isEmpty(const LinkedList *ll) {
    return ll->size == 0;
};

bool contains(const LinkedList *ll, const int value) {
    const Node* current = ll->head;

    while (current != NULL) {
        if (current->value == value) return true;
        current = current->next;
    }

    return false;
};

void print(const LinkedList* ll) {
    const Node* current = ll->head;

    while (current != NULL) {
        printf("%d - ", current->value);
        current = current->next;
    }
    printf("\n");
};

void destroyLinkedList(const LinkedList* ll) {
    Node* current = ll->head;

    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
};
