#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
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
    new_node->prev = last;
}

// Function to display the list from head to tail
void display(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
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

    // Inserting nodes
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);

    // Display the doubly linked list
    printf("Doubly Linked List: ");
    display(head);

    // Cleanup
    free_list(head);
    return 0;
}
