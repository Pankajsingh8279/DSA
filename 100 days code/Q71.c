/*Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

// Hash function
int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }

    printf("Hash table full\n");
}

void search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[idx] == -1) {
            break; 
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init();

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}