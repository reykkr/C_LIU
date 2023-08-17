#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char message[] = "Hello, Pipe!";
    char buffer[20];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    write(fd[1], message, sizeof(message));
    read(fd[0], buffer, sizeof(buffer));

    printf("Received message: %s\n", buffer);

    close(fd[0]);
    close(fd[1]);

    return 0;
}
