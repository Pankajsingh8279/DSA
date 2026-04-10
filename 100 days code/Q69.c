/*Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int dist;
} Pair;

// Min Heap
Pair heap[MAX];
int size = 0;

void swap(int i, int j) {
    Pair temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void push(int node, int dist) {
    heap[++size].node = node;
    heap[size].dist = dist;

    int i = size;
    while(i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i = i/2;
    }
}

Pair pop() {
    Pair top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while(2*i <= size) {
        int left = 2*i, right = 2*i+1, smallest = i;

        if(left <= size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if(right <= size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if(smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }

    return top;
}

// Graph (adjacency matrix)
int graph[MAX][MAX];
int n;

void dijkstra(int src) {
    int dist[MAX];

    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    push(src, 0);

    while(size > 0) {
        Pair p = pop();
        int u = p.node;

        for(int v = 0; v < n; v++) {
            if(graph[u][v] != 0) {
                int newDist = dist[u] + graph[u][v];

                if(newDist < dist[v]) {
                    dist[v] = newDist;
                    push(v, newDist);
                }
            }
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for(int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int edges;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove if directed
    }

    int src;
    printf("Enter source: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}