#include <stdio.h>
#include <limits.h>

#define N 10

int n;
int costMatrix[N][N];
int assignment[N];
int minCost = INT_MAX;

void branchAndBound(int worker, int costSoFar) {
    if (worker == n) {
        if (costSoFar < minCost) {
            minCost = costSoFar;
            for (int i = 0; i < n; i++) {
                printf("Worker %d is assigned to Task %d\n", i + 1, assignment[i] + 1);
            }
        }
        return;
    }

    for (int task = 0; task < n; task++) {
        if (costMatrix[worker][task] != -1) {
            if (costSoFar + costMatrix[worker][task] < minCost) {
                assignment[worker] = task;
                branchAndBound(worker + 1, costSoFar + costMatrix[worker][task]);
                assignment[worker] = -1;
            }
        }
    }
}

int main() {
    printf("Enter the number of workers/tasks (maximum %d): ", N);
    scanf("%d", &n);

    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        assignment[i] = -1;
    }

    printf("Minimum cost assignment:\n");
    branchAndBound(0, 0);
    printf("Minimum cost: %d\n", minCost);

    return 0;
}

