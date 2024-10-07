#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} LinearQueue;

// Function to create a queue
void createQueue(LinearQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(LinearQueue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(LinearQueue* q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to insert an element into the queue
void insert(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // First insertion
    }
    q->items[++q->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the queue
int delete(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete\n");
        return -1; // Return -1 for underflow
    }
    int item = q->items[q->front];
    if (q->front == q->rear) { // Queue is now empty
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to display the queue
void displayQueue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    LinearQueue q;
    createQueue(&q);

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
                insert(&q, value);
                break;
            case 2:
                value = delete(&q);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}