#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

int knapsack(int weights[], int values[], int capacity, int n) {
    int **profit = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; ++i) {
        profit[i] = (int *)calloc(capacity + 1, sizeof(int));
    }

    for (int i = 1; i <= n; ++i) {
        int wt = weights[i - 1];
        int val = values[i - 1];
        for (int w = 0; w <= capacity; ++w) {
            if (wt > w) profit[i][w] = profit[i - 1][w];
            else profit[i][w] = max(profit[i - 1][w], profit[i - 1][w - wt] + val);
        }
    }

    int result = profit[n][capacity];

    for (int i = 0; i <= n; ++i) free(profit[i]);
    free(profit);
    return result;
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int *weights = (int *)malloc(n * sizeof(int));
    int *values  = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Enter value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int capacity;
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int best = knapsack(weights, values, capacity, n);
    printf("Maximum value achievable = %d\n", best);

    free(weights);
    free(values);
    return 0;
}


