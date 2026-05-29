//Topological sort using Source Removal method

#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int src, dest, weight;
};

struct Graph{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;
    graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
    return graph;
}

void topologicalSort(int V, int graph[][V]){
    int indegree[V];
    for(int i = 0; i < V; ++i) indegree[i] = 0;

    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(graph[i][j]) indegree[j]++;
        }
    }

    int queue[V];
    int front = 0, rear = 0;

    for(int i = 0; i < V; ++i){
        if(indegree[i] == 0){
            queue[rear++] = i;
        }
    }

    int count = 0;
    int topo[V];

    while(front < rear){
        int u = queue[front++];
        topo[count++] = u;

        for(int v = 0; v < V; ++v){
            if(graph[u][v]){
                indegree[v]--;
                if(indegree[v] == 0){
                    queue[rear++] = v;
                }
            }
        }
    }

    if(count < V){
        printf("No Topological Sequence (cycle detected)\n");
    } else {
        printf("Topological Sort: ");
        for(int i = 0; i < count; ++i){
            if(i) printf(" ");
            printf("%d", topo[i]);
        }
        printf("\n");
    }
}

int main(){
    int V, E;
    printf("Enter number of vertices: ");
    if(scanf("%d", &V)!=1 || V<=0){
        printf("Invalid input\n");
        return 1;
    }

    int graph[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            graph[i][j]=0;
        }
    }
    printf("Enter the number of directed edges: ");
    scanf("%d", &E);
    printf("\nEnter %d directed edges(Source Destination)\n");
    for(int i=0;i<E;i++){
        int u, v;
        printf("Edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v]=1;
    }
    topologicalSort(V, graph);
    return 0;
}
