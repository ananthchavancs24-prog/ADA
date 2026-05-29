#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void qs(int* arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

void quickSort(int* arr, int n) {
    qs(arr, 0, n - 1);
}

int main() {
    int n;
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int array1[n];
    srand(time(0));

    printf("Generated array: ");
    for (int i = 0; i < n; i++) {
        array1[i] = rand() % 100;
        printf("%d ", array1[i]);
    }
    printf("\n");

    start = clock();
    quickSort(array1, n);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array1[i]);
    }
    printf("\nTime taken is: %f\n", time_taken);

    return 0;
}
