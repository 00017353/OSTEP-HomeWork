#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);
    int child1 = fork();
    int child2 = fork();
    if(child1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        printf("Hello from child process!\n");
        exit(0);
    }
    else if (child2 == 0) {
        waitpid(child1, NULL, 0);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        char buffer[128];
        fgets(buffer, sizeof(buffer), stdin);
        printf("I Received: %s\n", buffer);
        exit(0);
    }
    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}