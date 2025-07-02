#include <stdio.h>

#include "stack.h"

int main() {
    Stack stack = CreateStack();

    printf("Size: %llu\n", stack.size);
    printf("Empty: %d\n", IsEmpty(&stack));

    Display(stack);

    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);
    Push(&stack, 5);
    Push(&stack, 6);

    printf("\nSize: %llu\n", stack.size);
    printf("Empty: %d\n", IsEmpty(&stack));

    Display(stack);

    printf("Peek: %d\n", Peek(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Peek: %d\n", Peek(&stack));


    printf("\nSize: %llu\n", stack.size);
    printf("Empty: %d\n", IsEmpty(&stack));

    Display(stack);

    printf("Pop: %d\n", Pop(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Pop: %d\n", Pop(&stack));

    printf("\nSize: %llu\n", stack.size);
    printf("Empty: %d\n", IsEmpty(&stack));

    printf("Pop: %d\n", Pop(&stack));

    Display(stack);


    DestroyStack(&stack);

    return 0;
}
