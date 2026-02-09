/*A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh
*/
#include <stdio.h>
#include <string.h>
void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}
int main() {
    char codeName[100];
    printf("Enter the code name: ");
    scanf("%s", codeName);
    reverseString(codeName
);    printf("Transformed code name: %s\n", codeName);
    return 0;
}   