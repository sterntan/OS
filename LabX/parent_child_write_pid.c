#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *fp;

    fp = fopen("pids.txt", "w");
    if(fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    pid = fork();

    if(pid < 0) {
        perror("Fork failed");
        fclose(fp);
        return 1;
    }
    else if(pid == 0) {
        // Child process
        fprintf(fp, "Child PID: %d\n", getpid());
        fclose(fp);
        _exit(0);
    }
    else {
        // Parent process
        fprintf(fp, "Parent PID: %d\n", getpid());
        fclose(fp);
        wait(NULL); // Wait for child to finish
    }

    printf("Parent and child have written their PIDs to pids.txt.\n");
    return 0;
}

