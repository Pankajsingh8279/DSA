/*Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = 0;

// Add to queue
void enqueue(int x) {
    queue[rear++] = x;
}

// Remove from queue
int dequeue() {
    return queue[front++];
}

// BFS function
void BFS(int n, int adj[MAX][MAX], int source) {
    int visited[MAX] = {0};

    enqueue(source);
    visited[source] = 1;

    printf("BFS Traversal: ");

    while(front < rear) {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, source;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &source);

    BFS(n, adj, source);

    return 0;
}