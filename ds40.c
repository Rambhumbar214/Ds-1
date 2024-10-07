#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to find the union of two linked lists
Node* unionOfLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp;

    // Insert all elements from list1
    while (list1) {
        insert(&result, list1->data);
        list1 = list1->next;
    }

    // Insert all elements from list2 that are not already in result
    while (list2) {
        temp = result;
        int found = 0;
        while (temp) {
            if (temp->data == list2->data) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insert(&result, list2->data);
        }
        list2 = list2->next;
    }

    return result;
}

// Main function
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n1, n2, data;

    // Input for first linked list
    printf("Enter number of elements in the first list: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&list1, data);
    }

    // Input for second linked list
    printf("Enter number of elements in the second list: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&list2, data);
    }

    // Display both lists
    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Find and display the union of the lists
    Node* unionList = unionOfLists(list1, list2);
    printf("Union of both lists: ");
    displayList(unionList);

    // Free allocated memory (not shown for brevity)

    return 0;
}