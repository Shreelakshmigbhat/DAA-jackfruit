#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treap.h"

int main() {
    srand(time(NULL)); // ensures different priorities every run

    Node* root = NULL;

    // Sample input
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(keys)/sizeof(keys[0]);

    // Insert elements
    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal (sorted): ");
    inorder(root);
    printf("\n");

    // Search examples
    printf("Search 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    printf("Search 25: %s\n", search(root, 25) ? "Found" : "Not Found");

    // Delete example
    root = deleteNode(root, 50);

    printf("After deleting 50: ");
    inorder(root);
    printf("\n");

    // Free memory
    freeTree(root);

    return 0;
}
