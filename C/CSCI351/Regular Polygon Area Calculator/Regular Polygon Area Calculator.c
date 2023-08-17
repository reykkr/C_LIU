#include <stdio.h>
#include <math.h>

double area(int n, double side) {
    double numerator = n * side * side;
    double denominator = 4 * tan(M_PI / n);
    return numerator / denominator;
}

int main() {
    int numSides = 6; 
    double sideLength = 5.0; 
    
    double polygonArea = area(numSides, sideLength);
    
    printf("Area of the regular polygon: %.2lf\n", polygonArea);
    
    return 0;
}
