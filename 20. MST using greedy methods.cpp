#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->edges[src].src = src;
    graph->edges[src].dest = dest;
    graph->edges[src].weight = weight;

    graph->edges[dest].src = dest;
    graph->edges[dest].dest = src;
    graph->edges[dest].weight = weight;
}

void primMST(struct Graph* graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < graph->V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->V - 1; count++) {
        int minKey = INT_MAX, minIndex;

        for (int v = 0; v < graph->V; v++) {
            if (mstSet[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        mstSet[minIndex] = 1;

        for (int v = 0; v < graph->V; v++) {
            if (graph->edges[minIndex].weight > 0 && mstSet[v] == 0 && graph->edges[minIndex].weight < key[v]) {
                parent[v] = minIndex;
                key[v] = graph->edges[minIndex].weight;
            }
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < graph->V; i++) {
        printf("Edge: (%d, %d) Weight: %d\n", parent[i], i, key[i]);
    }
}

int main() {
    int V, E;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    primMST(graph);

    return 0;
}

