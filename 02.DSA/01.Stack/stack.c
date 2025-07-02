#include "stack.h"

#include <stdio.h>

Stack CreateStack() {
    Node* top = NULL;
    size_t size = 0;
    return (Stack){.top = top, .size = size};
}

void Push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int Pop(Stack* stack) {
    int returnValue = Peek(stack);

    if (IsEmpty(stack)) {
        ferror("Stack is Empty");
        return returnValue;
    }

    if (stack->size == 1) {
        free(stack->top);
        stack->top = NULL;
    } else {
        Node* currentVal = stack->top;
        stack->top = stack->top->next;
        free(currentVal);
    }
    stack->size--;

    return returnValue;
}

int Peek(Stack* stack) {
    return stack->top->value;
}

bool IsEmpty(Stack* stack) {
    return stack->size == 0;
}

void Display(const Stack stack) {
    Node* current = stack.top;

    while (current != NULL) {
        printf("\t- %d\n", current->value);
        current = current->next;
    }
}

void DestroyStack(Stack* stack) {
    Node* current = stack->top;

    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}
