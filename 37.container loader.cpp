#include <stdio.h>

#define MAX_ITEMS 100

void loadContainers(int items[], int numItems, int containerLength) {
    int containerCount = 0;
    int currentLength = 0;

    printf("Container %d:\n", containerCount + 1);
    for (int i = 0; i < numItems; i++) {
        if (currentLength + items[i] <= containerLength) {
            printf("%d ", items[i]);
            currentLength += items[i];
        } else {
            printf("\n");
            currentLength = items[i];
            printf("Container %d:\n", ++containerCount + 1);
            printf("%d ", items[i]);
        }
    }
    printf("\nTotal number of containers used: %d\n", containerCount + 1);
}

int main() {
    int items[MAX_ITEMS];
    int numItems, containerLength;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the length of each item: ");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the length of each container: ");
    scanf("%d", &containerLength);

    loadContainers(items, numItems, containerLength);

    return 0;
}

