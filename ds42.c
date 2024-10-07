#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

// Function to initialize the graph
void initializeGraph(Graph* g, int numNodes) {
    g->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1; // Directed edge from src to dest
}

// Function to perform BFS
void BFS(Graph* g, int start) {
    int visited[MAX_NODES] = {0}; // Initialize visited array
    int queue[MAX_NODES], front = 0, rear = -1;

    visited[start] = 1; // Mark the starting node as visited
    queue[++rear] = start; // Enqueue the starting node

    printf("BFS Traversal: ");

    while (front <= rear) {
        int current = queue[front++]; // Dequeue the front node
        printf("%d ", current); // Print the current node

        // Enqueue all adjacent unvisited nodes
        for (int i = 0; i < g->numNodes; i++) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue the node
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    Graph g;
    int numNodes, numEdges, src, dest;

    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);
    initializeGraph(&g, numNodes);

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    int startNode;
    printf("Enter starting node for BFS: ");
    scanf("%d", &startNode);

    BFS(&g, startNode);

    return 0;
}