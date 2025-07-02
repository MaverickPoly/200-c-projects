#include <stdio.h>

#include "hast_table.h"


int main() {
    HashTable* t = init_hash_table(10);

    display(t);

    insert(t, 56, 8);
    insert(t, 42, 6);
    insert(t, 777, 11);
    insert(t, 653, 9);
    insert(t, 33, 3);
    insert(t, 53, 14);
    insert(t, 46, 7);
    insert(t, 10, 0);
    printf("\n");
    display(t);

    printf("Contains 42: %d\n", contains_key(t, 42));
    printf("Contains 35: %d\n", contains_key(t, 35));
    printf("Delete 46: %d\n", delete(t, 46));
    printf("Delete 53: %d\n", delete(t, 53));
    printf("Delete 555: %d\n", delete(t, 555));


    printf("\n");
    display(t);

    destroy_table(t);

    return 0;
}
