#include <stdio.h>
void printPascalTriangle(int n) {
    int coefficients[n][n];
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
            if (i == 0 || i == line) {
                coefficients[line][i] = 1;
            } else {
                coefficients[line][i] = coefficients[line - 1][i - 1] + coefficients[line - 1][i];
            }
            printf("%d ", coefficients[line][i]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    printPascalTriangle(n);
    return 0;
}

