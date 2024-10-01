#include <stdio.h>
#include <stdlib.h>

// Structure for a singly linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the list
void insert_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
}

// Function to display the list
void display(Node *node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to search for a node
Node* search(Node *head, int data) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a node by value
void delete_node(Node **head, int data) {
    Node *temp = *head, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to free the list
void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    Node *head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    printf("Value %d found in the list.\n", data);
                } else {
                    printf("Value %d not found in the list.\n", data);
                }
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Cleanup
    free_list(head);
    return 0;
}
