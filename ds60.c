#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the structure for the stack
typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    }
}

// Function to remove an item from stack. It decreases top by 1
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return 0; // Return 0 if the stack is empty (should be handled better)
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    Stack* stack = createStack(100); // Create a stack to hold operands
    int i;

    for (i = 0; exp[i]; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0'); // Convert char to int
        } else {
            // If the character is an operator, pop two elements from stack
            int val2 = pop(stack);
            int val1 = pop(stack);

            switch (exp[i]) {
                case '+': push(stack, val1 + val2); break;
                case '-': push(stack, val1 - val2); break;
                case '*': push(stack, val1 * val2); break;
                case '/': push(stack, val1 / val2); break;
            }
        }
    }
    return pop(stack); // The result is in the top of the stack
}

// Main function
int main() {
    char exp[100];

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}