#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
typedef struct {
    int emp_id;
    char name[50];
    char address[100];
} Employee;

// Function to sort employees using bubble sort
void bubbleSort(Employee emp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (emp[j].emp_id > emp[j + 1].emp_id) {
                // Swap emp[j] and emp[j + 1]
                Employee temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
}

// Function to display employee details
void displayEmployees(Employee emp[], int n) {
    printf("\nEmployee Details:\n");
    printf("Emp ID\tName\t\tAddress\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\n", emp[i].emp_id, emp[i].name, emp[i].address);
    }
}

// Main function
int main() {
    int n;
    Employee emp[MAX_EMPLOYEES];

    printf("Enter the number of employees: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Emp ID: ");
        scanf("%d", &emp[i].emp_id);
        getchar(); // Consume newline character
        printf("Name: ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        emp[i].name[strcspn(emp[i].name, "\n")] = 0; // Remove newline character
        printf("Address: ");
        fgets(emp[i].address, sizeof(emp[i].address), stdin);
        emp[i].address[strcspn(emp[i].address, "\n")] = 0; // Remove newline character
    }

    bubbleSort(emp, n);
    displayEmployees(emp, n);

    return 0;
}