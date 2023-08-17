#include <stdio.h>

int main() {
    FILE *file;
    char text[] = "Hello, File I/O!";
    char buffer[100];

    file = fopen("output.txt", "w");
    if (file != NULL) {
        fprintf(file, "%s", text);
        fclose(file);
    }

    file = fopen("output.txt", "r");
    if (file != NULL) {
        fscanf(file, "%s", buffer);
        fclose(file);
        printf("Read from file: %s\n", buffer);
    }

    return 0;
}
