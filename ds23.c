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

// Function to concatenate two linked lists
void concatenate(Node **list1, Node *list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }
    
    Node *last = *list1;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = list2;
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
    Node *list1 = NULL;
    Node *list2 = NULL;

    // Inserting nodes into the first list
    insert_end(&list1, 1);
    insert_end(&list1, 2);
    insert_end(&list1, 3);

    // Inserting nodes into the second list
    insert_end(&list2, 4);
    insert_end(&list2, 5);

    // Displaying the lists
    printf("List 1: ");
    display(list1);
    
    printf("List 2: ");
    display(list2);

    // Concatenating the two lists
    concatenate(&list1, list2);

    // Displaying the concatenated list
    printf("Concatenated List: ");
    display(list1);

    // Cleanup
    free_list(list1);
    return 0;
}
