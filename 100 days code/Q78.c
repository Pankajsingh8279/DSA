/*Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

int graph[MAX][MAX];
int selected[MAX];
int key[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph with INF
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    // Initialize keys
    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        selected[i] = 0;
    }

    key[1] = 0;   // Start from node 1

    int totalWeight = 0;

    for(int count = 1; count <= n; count++) {
        int min = INT_MAX, u = -1;

        // Find minimum key vertex not selected
        for(int i = 1; i <= n; i++) {
            if(!selected[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        selected[u] = 1;
        totalWeight += key[u];

        // Update adjacent vertices
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && !selected[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}