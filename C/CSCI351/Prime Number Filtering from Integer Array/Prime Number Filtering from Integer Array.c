#include <stdio.h>

int is_prime(int num) {
    if (num <= 1)
        return 0;
    if (num <= 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }

    return 1;
}

int main() {
    int originalArray[10] = {2, 6, 11, 15, 23, 30, 37, 42, 50, 53};
    int primeArray[10];
    int originalSize = 10;
    int primeCount = 0;

    for (int i = 0; i < originalSize; ++i) {
        if (is_prime(originalArray[i])) {
            primeArray[primeCount] = originalArray[i];
            primeCount++;
            originalArray[i] = 0;
        }
    }

    printf("Original Array without Prime Numbers: ");
    for (int i = 0; i < originalSize; ++i) {
        if (originalArray[i] != 0) {
            printf("%d ", originalArray[i]);
        }
    }

    printf("\nPrime Numbers: ");
    for (int i = 0; i < primeCount; ++i) {
        printf("%d ", primeArray[i]);
    }

    return 0;
}