/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct node {
    int vertex;
    struct node* next;
};

struct node* adj[MAX];
int visited[MAX];

// Function to create a new node
struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to adjacency list
void addEdge(int u, int v) {
    struct node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, edges, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);     // For directed graph
        addEdge(v, u);     // Remove this line for directed graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    DFS(s);

    return 0;
}