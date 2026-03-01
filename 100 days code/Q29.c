/*Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode; 
}
void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k <= 0) return;

    struct Node* temp = *head;
    int length = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    temp->next = *head; 

    k = k % length; 
    int stepsToNewHead = length - k;

    for (int i = 0; i < stepsToNewHead; i++)
        temp = temp->next;

    *head = temp->next; 
    temp->next = NULL; 
}
void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n, value, k;
    struct Node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter number of rotations: ");
    scanf("%d", &k);

    rotateRight(&head, k);
    traverseList(head);

    return 0;
}
