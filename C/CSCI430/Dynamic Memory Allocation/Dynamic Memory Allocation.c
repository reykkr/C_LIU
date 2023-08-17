#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers;
    int size = 5;

    numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < size; ++i) {
        numbers[i] = i * 2;
    }

    size = 10;
    numbers = (int *)realloc(numbers, size * sizeof(int));
    if (numbers == NULL) {
        perror("realloc");
        return 1;
    }

    free(numbers);

    return 0;
}
