#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to display the adjacency list
void displayAdjacencyList(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    displayAdjacencyList(graph, n);

    return 0;
}