#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        printf("Child: My PID is %d\n", getpid());
    } else {
        printf("Parent: My PID is %d, Child PID is %d\n", getpid(), child_pid);
    }

    return 0;
}
