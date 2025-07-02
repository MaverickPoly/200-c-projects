#include <stdio.h>
#include "doublyLinkedList.h"


int main() {
    LinkedList* ll = createLinkedList();

    printf("Is Empty: %d\n", isEmpty(ll));
    printf("Size: %llu\n", size(ll));

    print(ll);

    // Adding
    append(ll, 5);
    append(ll, 4);
    append(ll, 6);
    append(ll, 7);
    prepend(ll, 8);
    prepend(ll, 3);
    print(ll);
    insert(ll, 10, 3);
    // insert(ll, 100, 100); // -> Error

    print(ll);

    printf("Is Empty: %d\n", isEmpty(ll));
    printf("Size: %llu\n", size(ll));

    // Removing
    printf("Pop: %d\n", pop(ll));
    printf("Pop: %d\n", pop(ll));
    deleteFirst(ll);
    removeDL(ll, 2);

    print(ll);

    printf("Contains 5: %d\n", contains(ll, 5));
    printf("Contains 2: %d\n", contains(ll, 2));

    destroyLinkedList(ll);

    return 0;
}