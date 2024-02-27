#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int capacity, int weights[], int values[], int num_items) {
    int dp[num_items + 1][capacity + 1];

    for (int i = 0; i <= num_items; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = (i == 0 || w == 0) ? 0 : max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
        }
    }
    return dp[num_items][capacity];
}
int main() {
    int num_items, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    int weights[num_items], values[num_items];
    for (int i = 0; i < num_items; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    int result = knapsack(capacity, weights, values, num_items);
    printf("Maximum value: %d\n", result);
    return 0;
}

