#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int dest;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numVertices;
    Edge** adjLists;
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency lists
    graph->adjLists = malloc(vertices * sizeof(Edge*));

    // Initialize adjacency lists
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Create a new edge from src to dest
    Edge* newEdge = malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;

    // Uncomment the next two lines for an undirected graph
    // newEdge = malloc(sizeof(Edge));
    // newEdge->dest = src; newEdge->next = graph->adjLists[dest]; graph->adjLists[dest] = newEdge;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* temp = graph->adjLists[i];
        while (temp) {
            Edge* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    int vertices, edges;

    // Accept number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create the graph
    Graph* graph = createGraph(vertices);

    // Accept edges
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Print the graph
    printf("\nAdjacency List Representation of the Graph:\n");
    printGraph(graph);

    // Free allocated memory
    freeGraph(graph);

    return 0;
}
