#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for operators
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

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* s, char item) {
    if (!isFull(s)) {
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

// Function to get the top element of the stack
char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0; // Return 0 for non-operators
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    createStack(&s);
    int i, j = 0;
    
    for (i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) { // If the character is an operand (number/letter)
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') { // Left parenthesis
            push(&s, infix[i]);
        } else if (infix[i] == ')') { // Right parenthesis
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        } else { // Operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    
    // Pop all the operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline character

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}