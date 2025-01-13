#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello from Parent";
    char buffer[100];

    // Create a pipe
    if(pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if(pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if(pid == 0) {
        // Child process
        close(pipefd[1]); // Close unused write end

        // Read message from pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received message: %s\n", buffer);

        close(pipefd[0]); // Close read end
    }
    else {
        // Parent process
        close(pipefd[0]); // Close unused read end

        // Write message to pipe
        write(pipefd[1], message, strlen(message)+1);
        printf("Parent sent message to child.\n");

        close(pipefd[1]); // Close write end
        wait(NULL); // Wait for child to finish
    }

    return 0;
}
