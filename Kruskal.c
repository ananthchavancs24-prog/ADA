#include <stdio.h>

#define MAX 20
#define INF 999

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}


void union_set(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, i, j, a, b, u, v;
    int cost[MAX][MAX];
    int min, mincost = 0, ne = 1;

    printf("Enter number of vertices:\n");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }


    for (i = 0; i < n; i++)
        parent[i] = 0;

    printf("Edges in MST:\n");

    while (ne < n) {
        min = INF;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);


        if (u != v) {
            printf("(%d - %d) = %d\n", a, b, min);
            mincost += min;
            union_set(u, v);
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
