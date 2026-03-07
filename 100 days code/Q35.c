/* Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    queue[++rear] = value;
}
void display() {
    if (front == -1) {
        return; 
    }
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i != rear) {
            printf(" ");
        }
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        enqueue(value);
    }
    display();
    return 0;
}
