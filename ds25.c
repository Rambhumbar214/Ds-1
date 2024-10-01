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
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverse(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    *head = prev; // Update the head to the new front
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

int main() {
    Node *head = NULL;

    // Inserting nodes into the list
    insert_end(&head, 1);
    insert_end(&head, 2);
    insert_end(&head, 3);
    insert_end(&head, 4);
    insert_end(&head, 5);

    // Displaying the original list
    printf("Original List: ");
    display(head);

    // Reversing the linked list
    reverse(&head);

    // Displaying the reversed list
    printf("Reversed List: ");
    display(head);

    // Cleanup
    free_list(head);
    return 0;
}
