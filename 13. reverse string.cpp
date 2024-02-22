#include <stdio.h>
void printReverse(char *str) {
    if (*str == '\0') {
        return;
    }
    printReverse(str + 1);
    printf("%c", *str);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Reverse of the string: ");
    printReverse(str);
    return 0;
}

