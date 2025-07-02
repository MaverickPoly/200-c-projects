#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data);
Node* insert(Node* root, int data);
Node* search(Node* root, int key);
Node* findMin(Node* node);
Node* deleteNode(Node* root, int key);
void inorder(Node* root);

#endif
