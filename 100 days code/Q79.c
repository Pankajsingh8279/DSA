/*Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005
#define INF INT_MAX

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* graph[MAX];

void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = graph[u];
    graph[u] = newNode;
}

/* Min Heap */
struct HeapNode {
    int vertex, dist;
};

struct HeapNode heap[MAX * MAX];
int heapSize = 0;

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(int vertex, int dist) {
    heap[++heapSize].vertex = vertex;
    heap[heapSize].dist = dist;

    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

struct HeapNode extractMin() {
    struct HeapNode minNode = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2 * i, right = 2 * i + 1;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else
            break;
    }

    return minNode;
}

void dijkstra(int n, int source) {
    int dist[MAX];
    
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;
    insertHeap(source, 0);

    while (heapSize > 0) {
        struct HeapNode current = extractMin();
        int u = current.vertex;

        struct Node* temp = graph[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w);   // Undirected graph
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}