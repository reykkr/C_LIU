#include <stdio.h>

#define ARRAY_SIZE 10

void removeDuplicates(int arr[], int *size) {
    for (int i = 0; i < *size; i++) {
        for (int j = i + 1; j < *size;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < *size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
            } else {
                j++;
            }
        }
    }
}

int main() {
    int originalArray[ARRAY_SIZE] = {10, 25, 50, 10, 75, 25, 100, 50, 30, 75};
    int size = ARRAY_SIZE;

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", originalArray[i]);
    }
    printf("\n");

    removeDuplicates(originalArray, &size);

    printf("Array without Duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", originalArray[i]);
    }
    printf("\n");

    return 0;
}