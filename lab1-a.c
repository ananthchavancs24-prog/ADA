#include <stdio.h>

int main() {
    int arr[] = {3,7,2,9,5};
    int n = 5, key = 9;
    int i, pos = -1;

    for(i = 0; i < n; i++){
        if(arr[i] == key){
            pos = i;
            break;
        }
    }

    if(pos != -1)
        printf("Found at index %d", pos);
    else
        printf("Not Found");

    return 0;
}
