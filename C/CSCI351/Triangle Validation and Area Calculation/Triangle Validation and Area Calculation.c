#include <stdio.h>
#include <math.h>

int isValid(double side1, double side2, double side3) {
    return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
}

double area(double side1, double side2, double side3) {
    double s = (side1 + side2 + side3) / 2.0;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

int main() {
    double side1, side2, side3;

    side1 = 3.0;
    side2 = 4.0;
    side3 = 5.0;

    if (isValid(side1, side2, side3)) {
        double triangleArea = area(side1, side2, side3);
        printf("Triangle is valid. Area: %.2lf\n", triangleArea);
    } else {
        printf("Invalid triangle.\n");
    }

    return 0;
}
