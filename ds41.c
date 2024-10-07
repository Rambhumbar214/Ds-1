#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
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

// Function to insert a new element in the BST
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

// Function for in-order traversal
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to count leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count total number of nodes
int countTotalNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

// Main function
int main() {
    Node* root = NULL;
    int n, data;

    printf("Enter number of elements to insert in BST: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("In-order Traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));
    printf("Total number of nodes: %d\n", countTotalNodes(root));

    return 0;
}