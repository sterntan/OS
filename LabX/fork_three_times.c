#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int i;

    // Forking 3 times
    for(i = 0; i < 3; i++) {
        pid = fork();

        if(pid < 0) {
            // Fork failed
            perror("Fork failed");
            return 1;
        }
        else if(pid == 0) {
            // Child process
            printf("Child %d: PID = %d\n", i+1, getpid());
            _exit(0);
        }
        else {
            // Parent process continues to fork
        }
    }

    // Parent process waits for all children to finish
    for(i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("Parent: All child processes have finished.\n");
    return 0;
}
