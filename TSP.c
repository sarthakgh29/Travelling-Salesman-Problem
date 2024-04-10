#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int distances[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int distances[]) {
    printf("Shortest distances from the source vertex:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }
}

// Function that implements Dijkstra's single-source shortest path algorithm
void dijkstra(int graph[V][V], int startVertex) {
    int distances[V]; // Output array to store the shortest distances from the source vertex
    int visited[V];   // Array to keep track of visited vertices

    // Initialize distances and visited arrays
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance from the source vertex to itself is always 0
    distances[startVertex] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(distances, visited);

        // Mark the picked vertex as visited
        visited[u] = 1;

        // Update distances of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX
                && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(distances);
}

// Driver program to test the above functions
int main() {
    // User input for the graph
    int graph[V][V];
    printf("Enter the graph adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Starting vertex
    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Run Dijkstra's algorithm
    dijkstra(graph, startVertex);

    return 0;
}
