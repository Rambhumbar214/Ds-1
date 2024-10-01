#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node; // Point to itself
    new_node->prev = new_node; // Point to itself
    return new_node;
}

// Function to create the doubly circular linked list
Node* create_list() {
    Node *head = NULL, *tail = NULL;
    int data, n;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        
        Node *new_node = create_node(data);
        
        if (head == NULL) {
            head = new_node; // Initialize head
            tail = new_node; // Initialize tail
        } else {
            tail->next = new_node; // Link new node to the last node
            new_node->prev = tail;  // Link last node to new node
        }
        
        new_node->next = head; // Link new node to head
        head->prev = new_node; // Link head to new node
        tail = new_node;       // Update tail
    }

    return head;
}

// Function to display the list
void display(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    Node *current = head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to delete a node at a given position
void delete_node(Node **head, int position) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    Node *current = *head;
    int count = 0;

    // If position is 0, delete the head
    if (position == 0) {
        if (current->next == current) { // Only one node in the list
            free(current);
            *head = NULL;
        } else {
            Node *tail = current->prev;
            tail->next = current->next; // Link tail to next node
            current->next->prev = tail; // Link next node to tail
            *head = current->next;      // Update head
            free(current);
        }
        printf("Node at position 0 deleted.\n");
        return;
    }

    // Traverse to find the position
    do {
        if (count == position) {
            current->prev->next = current->next; // Link previous node to next node
            current->next->prev = current->prev; // Link next node to previous node
            free(current);
            printf("Node at position %d deleted.\n", position);
            return;
        }
        current = current->next;
        count++;
    } while (current != *head);

    printf("Position %d is out of bounds.\n", position);
}

// Function to free the list
void free_list(Node *head) {
    if (head == NULL) return;

    Node *current = head;
    Node *next_node;

    do {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != head);
}

int main() {
    Node *head = NULL;
    int choice, position;

    do {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Delete a node at given position\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create_list();
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter position to delete (0-indexed): ");
                scanf("%d", &position);
                delete_node(&head, position);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Cleanup
    free_list(head);
    return 0;
}
