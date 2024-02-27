#include <stdio.h>
void findMaxMin(int arr[], int l, int r, int *max, int *min) {
    if (l == r) {
        *max = arr[l];
        *min = arr[l];
    } else if (r == l + 1) {
        if (arr[l] > arr[r]) {
            *max = arr[l];
            *min = arr[r];
        } else {
            *max = arr[r];
            *min = arr[l];
        }
    } else {
        int mid = (l + r) / 2;
        int max1, min1, max2, min2;
        findMaxMin(arr, l, mid, &max1, &min1);
        findMaxMin(arr, mid + 1, r, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}
int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int max, min;
    findMaxMin(arr, 0, arr_size - 1, &max, &min);
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);
    return 0;
}

