#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int edges[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

void initializeGraph(Graph* g, int numNodes) {
    g->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            g->edges[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->edges[src][dest] = 1; // Directed edge from src to dest
}

void DFSUtil(Graph* g, int node, int visited[]) {
    visited[node] = 1; // Mark the node as visited
    printf("%d ", node); // Print the node

    for (int i = 0; i < g->numNodes; i++) {
        if (g->edges[node][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph* g) {
    int visited[MAX_NODES] = {0}; // Initialize visited array
    for (int i = 0; i < g->numNodes; i++) {
        if (!visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
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

    printf("DFS Traversal of the graph: ");
    DFS(&g);
    printf("\n");

    return 0;
}