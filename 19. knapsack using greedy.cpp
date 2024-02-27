#include <stdio.h>
struct Item {
    int weight;
    int value;};
void knapsackGreedy(int capacity, struct Item items[], int n) {
    int i, j;
    float ratio[n];
    
    for (i = 0; i < n; i++) {
        ratio[i] = (float)items[i].value / items[i].weight;    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                struct Item tempItem = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempItem; } } }
    int currentWeight = 0;
    float totalValue = 0;
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Added item with weight %d and value %d\n", items[i].weight, items[i].value); }
			 }
    printf("Total value in the knapsack: %.2f\n", totalValue);}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value); }
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    knapsackGreedy(capacity, items, n);
    return 0;}

