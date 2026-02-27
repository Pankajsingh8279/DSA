/*Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
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

int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2)
        while (diff--) ptr1 = ptr1->next;
    else
        while (diff--) ptr2 = ptr2->next;

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {

    int n, m, value;

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

  
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1) {
        temp2 = head2;
        while (temp2) {
            if (temp1->data == temp2->data) {

                struct Node* prev = head2;
                if (prev == temp2) {
                    head2 = temp1;
                } else {
                    while (prev->next != temp2)
                        prev = prev->next;
                    prev->next = temp1;
                }
                break;
            }
            temp2 = temp2->next;
        }
        if (temp2) break;
        temp1 = temp1->next;
    }
   

    struct Node* result = findIntersection(head1, head2);

    if (result)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}