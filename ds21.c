#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *array;    // Pointer to the stack's array
    int top;       // Index of the top element
    int capacity;  // Maximum number of elements in the stack
} Stack;

// Function to create a stack of a given capacity
Stack* create_stack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;  // Stack is initially empty
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int is_full(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// Function to add an item to the stack
void push(Stack *stack, int item) {
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from the stack
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return an invalid value to indicate underflow
    }
    return stack->array[stack->top--];
}

// Function to free the stack memory
void free_stack(Stack *stack) {
    free(stack->array);
    free(stack);
}

// Main function to test the stack implementation
int main() {
    Stack *stack = create_stack(10);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    printf("Is stack empty? %s\n", is_empty(stack) ? "Yes" : "No");
    printf("Is stack full? %s\n", is_full(stack) ? "Yes" : "No");

    // Cleanup
    free_stack(stack);
    return 0;
}
