#include <stdio.h>
#include <stdbool.h>

#define V 10

int graph[V][V];
int path[V];
int vertices;

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCircuitUtil(int pos) {
    if (pos == vertices) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < vertices; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCircuit() {
    for (int i = 0; i < vertices; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamiltonianCircuitUtil(1) == false) {
        printf("Hamiltonian circuit does not exist.\n");
        return;
    }

    printf("Hamiltonian circuit exists: ");
    for (int i = 0; i < vertices; i++)
        printf("%d ", path[i]);
    printf("%d ", path[0]);
    printf("\n");
}

int main() {
    printf("Enter the number of vertices (maximum %d): ", V);
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (%d x %d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    hamiltonianCircuit();

    return 0;
}

