/* Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int n;

void topoSort() {
    int queue[MAX];
    int front = 0, rear = 0;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for(int i = 0; i < n; i++) {
            if(graph[node][i]) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if(count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int edges;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        indegree[v]++;
    }

    topoSort();

    return 0;
}