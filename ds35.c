#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function to create a circular queue
void createQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to insert an element into the queue
void insert(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the queue
int delete(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete\n");
        return -1; // Return -1 for underflow
    }
    int item = q->items[q->front];
    if (q->front == q->rear) { // Queue is now empty
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return item;
}

// Function to display the queue
void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    CircularQueue q;
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