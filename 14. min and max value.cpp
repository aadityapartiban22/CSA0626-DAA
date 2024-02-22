#include <stdio.h>

void findMinMax(int arr[], int size) {
    if (size == 0) {
        printf("Empty sequence, cannot find minimum and maximum.\n");
        return;
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
}

int main() {
    int n;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size. Please enter a positive size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter the list elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, n);

    return 0;
}

