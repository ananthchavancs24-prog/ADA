#include <stdio.h>
#include <stdbool.h>

void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobile_index = -1;

    for (int i = 0; i < n; i++) {
        if (dir[perm[i] - 1] == -1 && i != 0) { //left
            if (perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
        if (dir[perm[i] - 1] == 1 && i != n - 1) { //right
            if (perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }

    return mobile;
}

void johnsonTrotter(int n) {
    int perm[n];
    int dir[n];

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1;
    }

    printPermutation(perm, n);

    while (1) {
        int mobile = getMobile(perm, dir, n);
        if (mobile == 0)
            break;

        int pos;
        for (int i = 0; i < n; i++) {
            if (perm[i] == mobile) {
                pos = i;
                break;
            }
        }

        if (dir[mobile - 1] == -1) {
            int temp = perm[pos];
            perm[pos] = perm[pos - 1];
            perm[pos - 1] = temp;
            pos = pos - 1;
        } else {
            int temp = perm[pos];
            perm[pos] = perm[pos + 1];
            perm[pos + 1] = temp;
            pos = pos + 1;
        }

        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile) {
                dir[perm[i] - 1] *= -1;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);
    return 0;
}
