#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num, int divisor) {
    if (num <= 1) {
        return false;    }
    if (divisor == 1) {
        return true;    }
    if (num % divisor == 0) {
        return false;    }
    return isPrime(num, divisor - 1);}
void generatePrimesInRange(int start, int end) {
    if (start <= end) {
        if (isPrime(start, start / 2 + 1)) {
            printf("%d ", start);  }
        generatePrimesInRange(start + 1, end); }}
int main() {
    int n;
    printf("Enter the range for prime numbers: ");
    scanf("%d", &n);
    printf("Prime numbers in the range 1 to %d are:\n", n);
    generatePrimesInRange(1, n);
    return 0;}

