#include <stdio.h>
#include <string.h>

#define MAX_CITIES 100

// Define the structure for city
struct city {
    int city_code;
    char name[30];
};

// Function to perform linear search
int linearSearch(struct city cities[], int n, const char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(cities[i].name, name) == 0) {
            return cities[i].city_code; // Return the city code if found
        }
    }
    return -1; // Return -1 if not found
}

// Main function
int main() {
    struct city cities[MAX_CITIES];
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);
    getchar(); // Consume newline character

    for (int i = 0; i < n; i++) {
        printf("Enter city code and name for city %d: ", i + 1);
        scanf("%d", &cities[i].city_code);
        getchar(); // Consume newline character
        fgets(cities[i].name, sizeof(cities[i].name), stdin);
        cities[i].name[strcspn(cities[i].name, "\n")] = 0; // Remove newline character
    }

    char searchName[30];
    printf("Enter the city name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    int code = linearSearch(cities, n, searchName);
    if (code != -1) {
        printf("City Code of %s: %d\n", searchName, code);
    } else {
        printf("City not found.\n");
    }

    return 0;
}