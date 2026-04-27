#include <stdio.h>

#define LEFT -1
#define RIGHT 1

int getLargestMobile(int perm[], int dir[], int n) {
    int largestMobile = 0, index = -1;
    for (int i = 0; i < n; i++) {
        int neighbor = i + dir[i];
        if (neighbor >= 0 && neighbor < n && perm[i] > perm[neighbor]) {
            if (perm[i] > largestMobile) {
                largestMobile = perm[i];
                index = i;
            }
        }
    }
    return index;
}

void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", perm[i]);
    printf("\n");
}

// Johnson-Trotter algorithm
void johnsonTrotter(int n) {
    int perm[n], dir[n];

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int largestIndex = getLargestMobile(perm, dir, n);
        if (largestIndex == -1) break;

        int swapIndex = largestIndex + dir[largestIndex];
        int temp = perm[largestIndex];
        perm[largestIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        int tempDir = dir[largestIndex];
        dir[largestIndex] = dir[swapIndex];
        dir[swapIndex] = tempDir;

        for (int i = 0; i < n; i++)
            if (perm[i] > perm[swapIndex])
                dir[i] = -dir[i];

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("All permutations:\n");
    johnsonTrotter(n);
    return 0;
}
