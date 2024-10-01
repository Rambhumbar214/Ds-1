#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return the partition index
}

// Quick Sort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Function to find the nth smallest element
int find_nth_element(int arr[], int size, int n) {
    if (n <= 0 || n > size) {
        printf("Invalid value of n: %d\n", n);
        return -1; // Invalid n
    }
    
    quick_sort(arr, 0, size - 1); // Sort the array
    return arr[n - 1]; // Return the nth element (1-indexed)
}

int main() {
    int size, n;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of n to find the nth smallest element: ");
    scanf("%d", &n);

    int nth_element = find_nth_element(arr, size, n);
    if (nth_element != -1) {
        printf("The %dth smallest element is: %d\n", n, nth_element);
    }

    free(arr); // Free allocated memory
    return 0;
}
