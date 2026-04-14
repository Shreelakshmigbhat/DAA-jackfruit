#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treap.h"

int main() {
    srand(time(NULL)); // ensures different priorities every run

    Node* root = NULL;
    int n;
    int keyToSearch;
    int keyToDelete;

    printf("Enter the number of elements to insert: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        int key;

        if (scanf("%d", &key) != 1) {
            printf("Invalid input.\n");
            freeTree(root);
            return 1;
        }

        root = insert(root, key);
    }

    printf("Inorder traversal (sorted): ");
    inorder(root);
    printf("\n");

    printf("Enter a key to search: ");
    if (scanf("%d", &keyToSearch) != 1) {
        printf("Invalid input.\n");
        freeTree(root);
        return 1;
    }

    printf("Search %d: %s\n", keyToSearch, search(root, keyToSearch) ? "Found" : "Not Found");

    printf("Enter a key to delete: ");
    if (scanf("%d", &keyToDelete) != 1) {
        printf("Invalid input.\n");
        freeTree(root);
        return 1;
    }

    root = deleteNode(root, keyToDelete);

    printf("After deleting %d: ", keyToDelete);
    inorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
