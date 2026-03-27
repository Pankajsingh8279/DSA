/*Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue
struct Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int size() {
    return rear - front;
}

// Build Tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    front = rear = 0;
    enqueue(root);

    int leftToRight = 1;

    while (!isEmpty()) {
        int levelSize = size();
        int temp[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue();

            int index;
            if (leftToRight)
                index = i;
            else
                index = levelSize - 1 - i;

            temp[index] = node->data;

            if (node->left)
                enqueue(node->left);
            if (node->right)
                enqueue(node->right);
        }

        // Print level
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", temp[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}