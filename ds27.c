#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Structure for the queue
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Function to create a new queue
Queue* create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert an element into the queue
void enqueue(Queue *q, int data) {
    Node *new_node = create_node(data);
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

// Function to delete an element from the queue
void dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = q->front;
    q->front = q->front->next;
    
    // If the front becomes NULL, set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// Function to display the queue
void display(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node *current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the queue
void free_queue(Queue *q) {
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
}

// Main function
int main() {
    Queue *q = create_queue();
    int choice, data;

    do {
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
                scanf("%d", &data);
                enqueue(q, data);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Cleanup
    free_queue(q);
    return 0;
}
