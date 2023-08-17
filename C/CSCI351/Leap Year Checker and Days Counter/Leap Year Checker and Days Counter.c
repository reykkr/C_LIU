#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int numberOfDaysInAYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}

int main() {
    printf("Year\tDays\n");
    for (int year = 2000; year <= 2023; year++) {
        printf("%d\t%d\n", year, numberOfDaysInAYear(year));
    }
    return 0;
}
