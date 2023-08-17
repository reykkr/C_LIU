#include <stdio.h>

#define ARRAY_SIZE 10

int main() {
    double numbers[ARRAY_SIZE] = {1.5, 2.7, 3.2, 4.8, 5.1, 6.3, 7.9, 8.6, 9.0, 10.4};

    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += numbers[i];
    }

    double average = sum / ARRAY_SIZE;

    int above_average_count = 0;
    int below_average_count = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (numbers[i] > average) {
            above_average_count++;
        } else if (numbers[i] < average) {
            below_average_count++;
        }
    }

    printf("Average: %.2f\n", average);
    printf("Count of values above average: %d\n", above_average_count);
    printf("Count of values below average: %d\n", below_average_count);

    return 0;
}
