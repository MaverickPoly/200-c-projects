#include <stdio.h>

#include "linkedList.h"


int main() {
    LinkedList ll = createLinkedList();

    printf("Size: %llu\n", getSize(&ll));
    printf("Is empty: %d\n", isEmpty(&ll));

    append(&ll, 1);
    append(&ll, 2);
    append(&ll, 3);
    append(&ll, 4);
    prepend(&ll, 10);
    prepend(&ll, 11);

    print(&ll);

    printf("\nSize: %llu\n", getSize(&ll));
    printf("Is empty: %d\n", isEmpty(&ll));
    printf("Contains 1: %d\n", contains(&ll, 1));
    printf("Contains 100: %d\n", contains(&ll, 100));

    printf("Pop: %d\n", pop(&ll));
    printf("Pop: %d\n", pop(&ll));

    print(&ll);
    removeLL(&ll, 1);
    removeLL(&ll, 4);
    print(&ll);
    printf("\nSize: %llu\n", getSize(&ll));
    printf("Is empty: %d\n", isEmpty(&ll));

    destroyLinkedList(&ll);

    return 0;
}
