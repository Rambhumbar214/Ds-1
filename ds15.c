#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack* s, int item) {
    if (s->top == (MAX - 1)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Function to pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack s;
    initStack(&s);
    char* token = expression;

    while (*token) {
        if (isdigit(*token)) {
            // Push the number onto the stack
            push(&s, *token - '0');  // Convert char to int
        } else {
            // Pop two operands from the stack
            int op2 = pop(&s);
            int op1 = pop(&s);

            // Perform the operation based on the operator
            switch (*token) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
                default:
                    printf("Invalid operator: %c\n", *token);
                    exit(EXIT_FAILURE);
            }
        }
        token++;  // Move to the next character in the expression
    }

    // The final result is at the top of the stack
    return pop(&s);
}

// Main function
int main() {
    char expression[MAX];

    // Accept a postfix expression from the user
    printf("Enter a postfix expression (e.g., 53+82-*): ");
    fgets(expression, sizeof(expression), stdin);

    // Evaluate the postfix expression
    int result = evaluatePostfix(expression);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}
