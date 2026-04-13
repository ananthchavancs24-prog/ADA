#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int l, int r){
    if(l >= r) return;

    int pivot = arr[r];
    int i = l - 1;

    for(int j = l; j < r; j++){
        if(arr[j] < pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = t;

    int p = i + 1;

    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

int main(){
    int arr[50000];
    srand(time(NULL));

    for(int n = 10000; n <= 50000; n += 10000){

        for(int i = 0; i < n; i++)
            arr[i] = rand();

        clock_t start = clock();

        quickSort(arr, 0, n-1);

        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d \t time = %f seconds\n", n, time_taken);
    }

    return 0;
}
