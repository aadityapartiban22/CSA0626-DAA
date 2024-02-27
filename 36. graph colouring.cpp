#include <stdio.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int isSafe(int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int v, int n, int m) {
    if (v == n) {
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, n)) {
            colors[v] = c;

            if (graphColoring(v + 1, n, m)) {
                return 1;
            }

            colors[v] = 0;
        }
    }

    return 0;
}

int main() {
    int n, m;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    if (n > MAX_VERTICES) {
        printf("Error: Number of vertices exceeds the maximum allowed size.\n");
        return 1;
    }

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &m);

    if (graphColoring(0, n, m)) {
        printf("Graph coloring is possible. Colors assigned to vertices are:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("Graph coloring is not possible with %d colors.\n", m);
    }

    return 0;
}

