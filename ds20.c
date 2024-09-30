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

// Function to search for an element in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to create a mirror of the BST
Node* mirror(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    Node* mirroredNode = createNode(root->data);
    mirroredNode->left = mirror(root->right);
    mirroredNode->right = mirror(root->left);
    return mirroredNode;
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

    // Search for an element
    printf("Enter value to search: ");
    scanf("%d", &value);
    Node* searchResult = search(root, value);
    if (searchResult != NULL) {
        printf("Element %d found in the BST.\n", value);
    } else {
        printf("Element %d not found in the BST.\n", value);
    }

    // Create a mirror of the BST
    Node* mirroredRoot = mirror(root);
    printf("In-order Traversal of Mirrored BST: ");
    inOrder(mirroredRoot);
    printf("\n");

    return 0;
}
