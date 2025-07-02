#include <stdio.h>

#include "dynamic_list.h"

int main() {
    DynamicList* l = initDynamicList(10);

    display(l);
    printf("Size: %llu\n", getSize(l));
    printf("Is empty: %d\n", isEmpty(l));
    printf("Capacity: %llu\n", l->capacity);

    // Adding
    append(l, 1);
    append(l, 2);
    append(l, 3);
    append(l, 4);
    append(l, 5);
    append(l, 7);
    append(l, 8);
    insert(l, 5, 6);
    insert(l, 0, 0);
    insert(l, 9, 90);

    display(l);
    printf("Size: %llu\n", getSize(l));
    printf("Is empty: %d\n", isEmpty(l));
    printf("Capacity: %llu\n", l->capacity);

    printf("Get 0: %d\n", get(l, 0));
    printf("Get 5: %d\n", get(l, 5));
    set(l, 4, -4);

    display(l);
    printf("Contains 4: %d\n", contains(l, 4));
    printf("Contains 0: %d\n", contains(l, 0));

    // Removing
    printf("Pop: %d\n", pop(l));
    printf("Pop: %d\n", pop(l));
    printf("Pop: %d\n", pop(l));
    removeAt(l, 3);
    removeAt(l, 0);
    display(l);

    reverse(l);
    display(l);

    clear(l);
    display(l);


    freeDynamicList(l);

    return 0;
}
