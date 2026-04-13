#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX];
int temp[MAX];

void merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, k = l;

    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= r)
        temp[k++] = arr[j++];

    for(i = l; i <= r; i++)
        arr[i] = temp[i];
}

void mergeSort(int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
}

int main()
{
    srand(time(NULL));

    for(int i = 0; i < MAX; i++)
        arr[i] = rand() % 100000;

    printf("Input Size\tTime Taken (seconds)\n");

    for(int n = 10000; n <= 50000; n += 10000)
    {
        clock_t start = clock();

        mergeSort(0, n - 1);

        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\n", n, time_taken);
    }

    return 0;
}
