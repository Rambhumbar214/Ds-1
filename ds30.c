#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into the BST
Node* insert(Node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to get the height of the tree
int height(Node *node) {
    if (node == NULL) {
        return -1; // Height of empty tree is -1
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

// Function to print nodes at a given level
void print_level(Node *node, int level) {
    if (node == NULL) {
        return;
    }
    if (level == 0) {
        printf("%d ", node->data);
    } else {
        print_level(node->left, level - 1);
        print_level(node->right, level - 1);
    }
}

// Function to perform level order traversal
void level_order(Node *root) {
    int h = height(root);
    for (int i = 0; i <= h; i++) {
        print_level(root, i);
        printf("\n");
    }
}

// Main function
int main() {
    Node *root = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display BST Level Wise\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("BST Level Order Traversal:\n");
                level_order(root);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
