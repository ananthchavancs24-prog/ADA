#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyMax(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest])
        largest = left;
    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i) {
        swap(&a[i], &a[largest]);
        heapifyMax(a, n, largest);
    }
}

void heapifyMin(int a[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] < a[smallest])
        smallest = left;
    if(right < n && a[right] < a[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&a[i], &a[smallest]);
        heapifyMin(a, n, smallest);
    }
}

void heapSortMaxHeap(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(a, n, i);
    for(int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapifyMax(a, i, 0);
    }
}

void heapSortMinHeap(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(a, n, i);
    for(int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapifyMin(a, i, 0);
    }
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Max Heap Sort (Ascending Order)");
    printf("\n2. Min Heap Sort (Descending Order)");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("\nOriginal array: ");
    printArray(a, n);

    if(choice == 1) {
        heapSortMaxHeap(a, n);
        printf("Sorted array in ascending order: ");
        printArray(a, n);
    }
    else if(choice == 2) {
        heapSortMinHeap(a, n);
        printf("Sorted array in descending order: ");
        printArray(a, n);
    }
    else {
        printf("Invalid choice\n");
    }
    return 0;
}
