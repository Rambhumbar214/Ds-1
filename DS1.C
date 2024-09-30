#include <stdio.h>
#include <conio.h>
				     // Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
	int mid = left + (right - left) / 2;

	// Check if target is present at mid
	if (arr[mid] == target) {
	    return mid; // Target found
	}

	// If target is greater, ignore the left half
	if (arr[mid] < target) {
	    left = mid + 1;
	}
	// If target is smaller, ignore the right half
	else {
	    right = mid - 1;
	}
    }

    return -1; // Target not found
}

int main() {
    int size, target, result,i,arr[10];
    clrscr();
    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
   // int arr[size];

    // Input elements of the array
    printf("Enter %d sorted elements: ", size);
    for ( i = 0; i < size; i++) {
	scanf("%d", &arr[i]);
    }

    // Input the target value to search for
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform binary search
    result = binarySearch(arr, size, target);

    // Output the result
    if (result != -1) {
	printf("Element found at index: %d\n", result);
    } else {
	printf("Element not found in the array.\n");
    }
	getch();
    return 0;
}
