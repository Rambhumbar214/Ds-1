#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create an empty circular linked list
Node* createList() {
    return NULL; // Initially, the list is empty
}

// Function to insert a new node at the end of the circular linked list
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, point the new node to itself
        *head = newNode;
        newNode->next = newNode;
    } else {
        Node* temp = *head;
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        // Insert the new node
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node with the given key
void deleteNode(Node** head, int key) {
    if (*head == NULL) return; // List is empty

    Node *temp = *head, *prev = NULL;

    // If the node to be deleted is the head node
    if (temp->data == key) {
        if (temp->next == *head) {
            // If there is only one node
            free(temp);
            *head = NULL;
            return;
        } else {
            // Find the last node to update its next pointer
            while (temp->next != *head) {
                temp = temp->next;
            }
            // Update the head and the last node's next pointer
            Node* toDelete = *head;
            *head = (*head)->next;
            temp->next = *head;
            free(toDelete);
            return;
        }
    }

    // Traverse the list to find the node to be deleted
    while (temp->next != *head && temp->next->data != key) {
        temp = temp->next;
    }

    // If the node was not found
    if (temp->next == *head) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Node found, perform deletion
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function with a menu-driven interface
int main() {
    Node* head = createList();
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Circular Linked List: ");
                display(head);
                break;
            case 4:
                // Exit the program
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
