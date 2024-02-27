#include <stdio.h>
#include <stdlib.h>
struct Pair {
    int min;
    int max;
};
struct Pair findMinMax(int arr[], int left, int right) {
    struct Pair result, leftResult, rightResult;
    int mid;
    if (left == right) {
        result.min = arr[left];
        result.max = arr[right];
        return result;    }
    if (right == left + 1) {
        result.min = (arr[left] < arr[right]) ? arr[left] : arr[right];
        result.max = (arr[left] > arr[right]) ? arr[left] : arr[right];
        return result;    }
    mid = (left + right) / 2;
    leftResult = findMinMax(arr, left, mid);
    rightResult = findMinMax(arr, mid + 1, right);
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;
    return result;}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);    }
    struct Pair result = findMinMax(arr, 0, n - 1);
    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);
    free(arr);
    return 0;}

