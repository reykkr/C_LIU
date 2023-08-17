#include <stdio.h>

void printChars(char ch1, char ch2, int numberPerLine) {
    int count = 0;

    for (char ch = ch1; ch <= ch2; ++ch) {
        printf("%c ", ch);
        count++;

        if (count == numberPerLine) {
            printf("\n");
            count = 0;
        }
    }

    if (count != 0) {
        printf("\n");
    }
}

int main() {
    printChars('1', 'Z', 10);

    return 0;
}