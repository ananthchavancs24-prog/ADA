#include <stdio.h>
#include <stdlib.h>
#define MAX 8


int board[MAX];
int n, solutionCount = 0;
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col) return 0;
        if (abs(board[i] - col) == abs(i - row)) return 0;
    }
    return 1;
}


void printBoard() {
    printf("\nPossibility %d:\n\n", ++solutionCount);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}


void nQueens(int row) {
    if (row == n) {
        printBoard();
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            nQueens(row + 1);
        }
    }
}


int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid input!\n");
        return 0;
    }
    nQueens(0);
    if (solutionCount == 0)
        printf("\nNo solutions exist.\n");
    else
        printf("\nTotal solutions = %d\n", solutionCount);
    return 0;
}


