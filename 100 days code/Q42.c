/*Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

typedef struct {
    int arr[MAX];
    int top;
} Stack;


void enqueue(Queue *q, int val) {
    q->arr[++q->rear] = val;
}

int dequeue(Queue *q) {
    return q->arr[q->front++];
}

int isQueueEmpty(Queue *q) {
    return q->front > q->rear;
}

void push(Stack *s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int main() {

    int n, x;
    Queue q;
    Stack s;

    q.front = 0;
    q.rear = -1;
    s.top = -1;
    printf("Enter integrers: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    while(!isQueueEmpty(&q)) {
        push(&s, dequeue(&q));
    }


    while(!isStackEmpty(&s)) {
        enqueue(&q, pop(&s));
    }


    while(!isQueueEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}