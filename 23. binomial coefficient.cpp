#include <stdio.h>
int binomialCoefficient(int n, int k) {
    int C[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}
int main() {
    int n, k;
    printf("Enter values for n and k (separated by space): ");
    scanf("%d %d", &n, &k);
    if (n < 0 || k < 0 || k > n) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Binomial Coefficient C(%d, %d) is %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}

