#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int child = fork();
    pid_t parentPid = getpid();
    if (child == 0) {
        close(STDOUT_FILENO);
        printf("Child Process\n");  
        exit(0);      
    } else {
        printf("Parent Process\n");
    }    
}