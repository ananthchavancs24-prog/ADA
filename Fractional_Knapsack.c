#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;

    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    return 0;
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    double maxValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            maxValue += items[i].value;
        } else {
            maxValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    double result = fractionalKnapsack(capacity, items, n);

    printf("Maximum value = %.2lf\n", result);

    return 0;
}
