#ifndef TREAP_H
#define TREAP_H

// Basic structure of a Treap node
typedef struct Node {
    int key;        // value stored in node
    int priority;   // random priority (heap property)
    struct Node *left, *right;
} Node;

// Core operations
Node* createNode(int key);
Node* insert(Node* root, int key);
Node* deleteNode(Node* root, int key);
int search(Node* root, int key);

// Utility functions
void inorder(Node* root);
void freeTree(Node* root);

#endif
