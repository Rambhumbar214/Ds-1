#include <stdio.h>
#include <stdlib.h>

// Structure for Stack
typedef struct Stack {
    int* arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
    printf("Pushed %d to the stack.\n", item);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1; // Return -1 for underflow
    }
    return stack->arr[stack->top--];
}

// Main function
int main() {
    int capacity;

    printf("Enter stack capacity: ");
    scanf("%d", &capacity);
    Stack* stack = createStack(capacity);

    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if empty\n");
        printf("4. Check if full\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                printf("Stack is %s.\n", isEmpty(stack) ? "empty" : "not empty");
                break;
            case 4:
                printf("Stack is %s.\n", isFull(stack) ? "full" : "not full");
                break;
            case 5:
                // Free allocated memory
                free(stack->arr);
                free(stack);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}