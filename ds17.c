#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

// Structure to hold employee information
typedef struct Employee {
    int emp_no;
    char name[NAME_LENGTH];
} Employee;

// Function to compare two Employee names
int compare(const void* a, const void* b) {
    Employee* empA = (Employee*)a;
    Employee* empB = (Employee*)b;
    return strcmp(empA->name, empB->name);
}

// Function to perform bubble sort on the employee array
void bubbleSort(Employee* employees, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare(&employees[j], &employees[j + 1]) > 0) {
                // Swap employees[j] and employees[j + 1]
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    // Open the file for reading
    FILE* file = fopen("employee.txt", "r");
    if (file == NULL) {
        printf("Could not open file employee.txt\n");
        return 1;
    }

    // Read employee data from the file
    while (fscanf(file, "%d %49s", &employees[count].emp_no, employees[count].name) != EOF) {
        count++;
    }
    fclose(file);

    // Sort the employees by name using bubble sort
    bubbleSort(employees, count);

    // Display the sorted employee data
    printf("Employee data sorted by name:\n");
    for (int i = 0; i < count; i++) {
        printf("Emp No: %d, Name: %s\n", employees[i].emp_no, employees[i].name);
    }

    return 0;
}
