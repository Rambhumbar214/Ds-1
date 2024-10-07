#include <stdio.h>
#include <stdlib.h>

// Define the structure for Queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to insert an element into the queue
void insert(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the queue
int delete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete.\n");
        return -1; // Return -1 for underflow
    }
    Node* temp = q->front;
    int item = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; // Queue is now empty
    }
    free(temp);
    return item;
}

// Main function
int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Check if empty\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(q, value);
                break;
            case 2:
                value = delete(q);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                if (isEmpty(q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                free(q);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}