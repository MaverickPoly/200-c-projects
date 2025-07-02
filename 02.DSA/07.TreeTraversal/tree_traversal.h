#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H


#include <stdlib.h>
#include <stdio.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node* data[MAX];
    int front;
    int rear;
} Queue;

Node* createNode(int data);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

void initQueue(Queue *q);
int isEmpty(Queue* q);
void enqueue(Queue* q, Node* node);
Node* dequeue(Queue* q);
void levelOrder(Node* root);

#endif
