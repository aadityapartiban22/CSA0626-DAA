#include <stdio.h>
#include <limits.h>
#define MAX 10
int n;
int graph[MAX][MAX];
int dp[MAX][1 << MAX];
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newMask = mask | (1 << city);
            int newAns = graph[pos][city] + tsp(newMask, city);

            ans = (ans < newAns) ? ans : newAns;
        }
    }
    dp[pos][mask] = ans;
    return ans;
}
int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }
    int result = tsp(1, 0);

    printf("The minimum cost of the TSP is: %d\n", result);

    return 0;
}

