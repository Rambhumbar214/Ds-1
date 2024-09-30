#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int top;
    char items[MAX];
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
void push(Stack* s, char item) {
    if (s->top == (MAX - 1)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Function to pop an item from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to reverse a string using a stack
void reverseString(char* str) {
    Stack s;
    initStack(&s);
    int length = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(&s, str[i]);
    }

    // Pop all characters from the stack and overwrite the original string
    for (int i = 0; i < length; i++) {
        str[i] = pop(&s);
    }
}

// Main function
int main() {
    char str[MAX];

    // Accept a string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    // Display the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
