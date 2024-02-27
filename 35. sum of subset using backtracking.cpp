#include <stdio.h>

#define MAX 50

void subsetSum(int set[], int n, int targetSum, int subset[], int subsetSize, int sum, int k) {
    if (sum == targetSum) {
        printf("{");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d", subset[i]);
            if (i < subsetSize - 1) {
                printf(", ");
            }
        }
        printf("}\n");
        return;
    }

    for (int i = k; i < n; i++) {
        subset[subsetSize] = set[i];
        subsetSum(set, n, targetSum, subset, subsetSize + 1, sum + set[i], i + 1);
    }
}

int main() {
    int n, targetSum;

    printf("Enter the size of the set: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: Size of the set exceeds the maximum allowed size.\n");
        return 1;
    }

    int set[MAX];

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int subset[MAX];

    printf("\nSubsets with the sum %d are:\n", targetSum);
    subsetSum(set, n, targetSum, subset, 0, 0, 0);

    return 0;
}

