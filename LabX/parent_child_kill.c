#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void signal_handler(int signum) {
    printf("Child received signal: %d\n", signum);
    exit(0);
}

int main() {
    pid_t pid;

    pid = fork();

    if(pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if(pid == 0) {
        // Child process
        // Register signal handler
        signal(SIGUSR1, signal_handler);

        printf("Child waiting for signal...\n");
        while(1) {
            pause(); // Wait for signal
        }
    }
    else {
        // Parent process
        sleep(1); // Ensure child is ready
        printf("Parent sending SIGUSR1 to child.\n");
        kill(pid, SIGUSR1);

        wait(NULL); // Wait for child to finish
    }

    return 0;
}
