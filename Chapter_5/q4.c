#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int child = fork();
    if (child == 0) {
        printf("Child Process\n");        
    } else {
        printf("Parent Process\n");
    }    
}