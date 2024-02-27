#include <stdio.h>

void findFactors(int n, int i) {
    if (i <= n) {
        if (n % i == 0) {
            printf("%d ", i);
        }
        findFactors(n, i + 1);
    }
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);
    findFactors(n, 1);

    return 0;
}

