#include <stdio.h>

void printPattern(int n, int i, int j) {
    if (i > n) {
        return;
    }
    if (j <= i) {
        printf("%d ", j);
        printPattern(n, i, j + 1);
    } else {
        printf("\n");
        printPattern(n, i + 1, 1);
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printPattern(n, 1, 1);

    return 0;
}

