#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to count non-leaf nodes
int countNonLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;

    if (root->left != NULL || root->right != NULL) {
        count = 1; // Current node is a non-leaf node
    }

    return count + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// Function to count leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1; // Current node is a leaf node
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to display the BST (in-order traversal)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main function
int main() {
    Node* root = NULL;
    int n, value;

    // Accept the number of nodes
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Insert nodes into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display the BST
    printf("In-order Traversal of BST: ");
    inOrder(root);
    printf("\n");

    // Count non-leaf and leaf nodes
    int nonLeafCount = countNonLeafNodes(root);
    int leafCount = countLeafNodes(root);

    printf("Number of non-leaf nodes: %d\n", nonLeafCount);
    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}
