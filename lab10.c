#include <stdio.h>
#include <stdlib.h>

int board[10], n;

int isSafe(int row, int col) {
    int i;

    for (i = 1; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }

    return 1;
}

void solve(int row) {
    int col, i;

    if (row > n) {
        for (i = 1; i <= n; i++) {
            printf("%d ", board[i]);
        }
        printf("\n");
        return;
    }

    for (col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(1);

    return 0;
}
