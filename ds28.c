#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to display the in-degree and out-degree of each node
void display_degrees(int adj_matrix[MAX_NODES][MAX_NODES], int nodes) {
    for (int i = 0; i < nodes; i++) {
        int in_degree = 0;
        int out_degree = 0;

        for (int j = 0; j < nodes; j++) {
            if (adj_matrix[i][j] == 1) {
                out_degree++; // Count outgoing edges
            }
            if (adj_matrix[j][i] == 1) {
                in_degree++; // Count incoming edges
            }
        }

        printf("Node %d: In-degree = %d, Out-degree = %d\n", i, in_degree, out_degree);
    }
}

int main() {
    int adj_matrix[MAX_NODES][MAX_NODES] = {0}; // Adjacency matrix
    int nodes;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", nodes, nodes);
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    // Display the in-degree and out-degree of each node
    display_degrees(adj_matrix, nodes);

    return 0;
}
