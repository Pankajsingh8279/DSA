/*Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long sum;
    long long freq;
    struct Node* next;
} Node;

#define SIZE 100003

Node* table[SIZE] = {NULL};  


int hash(long long key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

long long getFreq(long long sum) {
    int idx = hash(sum);
    Node* temp = table[idx];

    while (temp) {
        if (temp->sum == sum)
            return temp->freq;
        temp = temp->next;
    }
    return 0;
}


void insert(long long sum) {
    int idx = hash(sum);
    Node* temp = table[idx];

    while (temp) {
        if (temp->sum == sum) {
            temp->freq++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->freq = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    long long arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long prefix = 0;
    long long count = 0;

    insert(0); 

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        count += getFreq(prefix);  
        insert(prefix);
    }

    printf("Number of subarrays with sum zero: %lld\n", count);

    return 0;
}