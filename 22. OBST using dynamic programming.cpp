#include <stdio.h>
#include <limits.h>
float sumOfProbabilities(float probabilities[], int i, int j) {
    float sum = 0;
    for (int k = i; k <= j; k++) {
        sum += probabilities[k]; }
    return sum;}
float optimalBSTCost(float probabilities[], int n) {
    float cost[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cost[i][j] = 0;
        }
    }
    for (int length = 1; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sumOfProbabilities(probabilities, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }
    return cost[0][n - 1];
}
int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    float probabilities[n];
    printf("Enter the probabilities of keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &probabilities[i]);
    }
    float optimalCost = optimalBSTCost(probabilities, n);
    printf("Optimal Binary Search Tree Cost: %.2f\n", optimalCost);
    return 0;
}

