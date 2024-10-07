#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function to create a stack
void createStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, char item) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = item;
    }
}

// Function to pop an element from the stack
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check if the given expression has balanced parentheses
int isBalanced(char* expr) {
    Stack s;
    createStack(&s);

    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') {
            push(&s, expr[i]);
        } else if (expr[i] == ')') {
            if (isEmpty(&s)) {
                return 0; // Unmatched closing parenthesis
            }
            pop(&s); // Match found
        }
    }
    return isEmpty(&s); // If stack is empty, parentheses are balanced
}

// Main function
int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; // Remove newline character

    if (isBalanced(expression)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does not have balanced parentheses.\n");
    }

    return 0;
}