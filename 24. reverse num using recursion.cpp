#include <stdio.h>
int reverseNumber(int num, int reversed) {
    if (num == 0) {
        return reversed;
    } else {
        int lastDigit = num % 10;
        reversed = reversed * 10 + lastDigit;
        return reverseNumber(num / 10, reversed);
    }
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }
    int reversed = reverseNumber(num, 0);
    printf("Reverse of %d is %d\n", num, reversed);
    return 0;
}

