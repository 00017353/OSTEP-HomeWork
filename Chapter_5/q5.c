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
        waitpid(parentPid, NULL, 0);
        int grandchild = fork();
        if (grandchild == 0) {
            printf("Grrandchild Proces\n");
            exit(0);
        } else {
            printf("Child Process\n");  
            exit(0);      
        }        
    } else {
        printf("Parent Process\n");
    }    
}