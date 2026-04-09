/* Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;
void dfs(int node) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = node;
}

void topoSort() {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int edges;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topoSort();

    return 0;
}