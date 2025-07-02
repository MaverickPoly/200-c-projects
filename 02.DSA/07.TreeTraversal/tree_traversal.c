#include "tree_traversal.h"


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


// Queue
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX) {
        q->data[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(&q, current->left);
        if (current->right != NULL)
            enqueue(&q, current->right);
    }
}
