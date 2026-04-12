#include <stdio.h>
#include <stdlib.h>
#include "treap.h"

/*
    Function: createNode
    --------------------
    Creates a new Treap node.

    Why random priority?
    → This is the core idea of Treap.
    → Random priorities simulate random insertion order,
      which helps keep the tree balanced on average.
*/
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Assign key (used for BST ordering)
    newNode->key = key;

    // Assign random priority (used for heap property)
    newNode->priority = rand();

    // Initially, node has no children
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/*
    Function: rotateRight
    ---------------------
    Performs right rotation to fix heap violation.

    When do we need this?
    → If left child has smaller priority than parent
      (violates min-heap property)

    Structure before rotation:

          y
         /
        x
         \
         T2

    After rotation:

          x
           \
            y
           /
          T2

    Effect:
    → Maintains BST property
    → Fixes heap property
*/
Node* rotateRight(Node* y) {
    Node* x = y->left;      // left child becomes new root
    Node* T2 = x->right;    // subtree to be repositioned

    // Perform rotation
    x->right = y;
    y->left = T2;

    return x; // return new root
}


/*
    Function: rotateLeft
    --------------------
    Performs left rotation to fix heap violation.

    Used when:
    → Right child has smaller priority than parent

    Before:

        x
         \
          y
         /
        T2

    After:

          y
         /
        x
         \
          T2
*/
Node* rotateLeft(Node* x) {
    Node* y = x->right;     // right child becomes new root
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}


/*
    Function: insert
    ----------------
    Inserts a key into the Treap.

    Two-step logic:

    STEP 1: Insert like a normal BST
    → Ensures ordering of keys

    STEP 2: Fix heap property using rotations
    → Ensures smaller priority moves upward

    Important:
    → Priority decides structure
    → Key decides ordering
*/
Node* insert(Node* root, int key) {

    // Base case: empty position found
    if (root == NULL)
        return createNode(key);

    // BST insertion (based on key)
    if (key < root->key) {
        root->left = insert(root->left, key);

        // After insertion, check heap property
        // If violated → rotate
        if (root->left->priority < root->priority)
            root = rotateRight(root);
    }
    else {
        root->right = insert(root->right, key);

        if (root->right->priority < root->priority)
            root = rotateLeft(root);
    }

    return root;
}


/*
    Function: deleteNode
    --------------------
    Deletes a node from the Treap.

    Strategy:
    → First find the node (like BST)
    → Then push it DOWN using rotations
    → Finally delete when it becomes a leaf

    Why rotate down?
    → Because we must preserve heap + BST properties
*/
Node* deleteNode(Node* root, int key) {

    // Base case: node not found
    if (root == NULL)
        return NULL;

    // Traverse tree like BST
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node found

        // Case 1: No left child → replace with right
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child → replace with left
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Both children exist
        // Choose rotation based on smaller priority
        if (root->left->priority < root->right->priority) {
            root = rotateRight(root);
            root->right = deleteNode(root->right, key);
        }
        else {
            root = rotateLeft(root);
            root->left = deleteNode(root->left, key);
        }
    }

    return root;
}


/*
    Function: search
    ----------------
    Searches for a key in the Treap.

    Works exactly like BST search:
    → Go left if key is smaller
    → Go right if key is larger
*/
int search(Node* root, int key) {

    if (root == NULL)
        return 0; // not found

    if (root->key == key)
        return 1; // found

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}


/*
    Function: inorder
    -----------------
    Performs inorder traversal.

    Why inorder?
    → In BST, inorder traversal gives sorted order.
    → Used to verify correctness of Treap.
*/
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}


/*
    Function: freeTree
    ------------------
    Frees all allocated memory.

    Important in C:
    → Avoid memory leaks
*/
void freeTree(Node* root) {

    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}
