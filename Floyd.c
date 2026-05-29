//Floyds Algo


#include <stdio.h>
#define MAX 100
#define INF 99999

void floyd(int n, int cost[MAX][MAX]){
    int i, j, k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(cost[i][k]+cost[k][j]<cost[i][j]){
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }
    printf("\nAll Pair-Shortest Path Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(cost[i][j]==INF)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, i, j, k;
    int cost[MAX][MAX];
    printf("Enter number of vertices(between 3 and 100): ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }
    floyd(n, cost);
    return 0;
}
