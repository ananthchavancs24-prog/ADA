#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void merge(int arr[], int low, int mid, int high){
    int temp[high-low+1], k=0;
    int i=low, j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i];
            i++;
        }
        else{
            temp[k++]=arr[j];
            j++;
        }
    }
    while(i<=mid){
        temp[k++]=arr[i];
        i++;
    }
    while(j<=high){
        temp[k++]=arr[j];
        j++;
    }
    for(int i=0;i<k;i++){
        arr[low+i]=temp[i];
    }
}

void mergeSort(int arr[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void ms(int arr[], int n){
    mergeSort(arr, 0, n-1);
}

int main(){
    int n, i;
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int array1[n];
    srand(time(0));

    printf("Generated array: ");
    for(int i=0;i<n;i++){
        array1[i]=rand()%100;
        printf("%d ", array1[i]);
    }
    printf("\n");

    start=clock();
    ms(array1, n);
    end=clock();
    printf("\n");

    double time_taken=((double)(end-start))/ CLOCKS_PER_SEC;

    printf("Sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ", array1[i]);
    }
    printf("\nTime taken is: %f", time_taken);
    return 0;
}
