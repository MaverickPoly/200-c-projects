#include <stdio.h>
#include "binary_search_tree.h"


int main() {
    Node* root = NULL;

    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal of BST: ");
    inorder(root);
    putchar('\n');

    int key = 60;
    Node* found = search(root, key);
    if (found)
        printf("Found %d in BST\n", key);
    else
        printf("%d not found in BST\n", key);

    // Delete
    root = deleteNode(root, 50);
    printf("Inorder after deleting 50:\n");
    inorder(root);
    printf("\n");

    return 0;
}