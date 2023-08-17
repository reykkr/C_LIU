#include <stdio.h>

int main() {
    int originalArray[10] = {2, 5, 10, 7, 4, 9, 6, 3, 8, 1};
    int oddArray[10];
    int evenArray[10];
    int oddCount = 0;
    int evenCount = 0;

    for (int i = 0; i < 10; ++i) {
        if (originalArray[i] % 2 == 0) {
            evenArray[evenCount] = originalArray[i];
            evenCount++;
        } else {
            oddArray[oddCount] = originalArray[i];
            oddCount++;
        }
    }

    printf("Original Array: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", originalArray[i]);
    }
    printf("\n");

    printf("Even Array: ");
    for (int i = 0; i < evenCount; ++i) {
        printf("%d ", evenArray[i]);
    }
    printf("\n");

    printf("Odd Array: ");
    for (int i = 0; i < oddCount; ++i) {
        printf("%d ", oddArray[i]);
    }
    printf("\n");

    return 0;
}