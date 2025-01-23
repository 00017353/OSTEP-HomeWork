#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    int child = fork();
    if (child == 0) {
        printf("Child process. FD: %d\n", fd);
        char *text = "Hello!\n";
        write(fd, text, strlen(text));
    } else {
        wait(NULL);
        char *text = "Good Bye!\n";
        write(fd, text, strlen(text));
        printf("Parent process. FD: %d\n", fd);
    }
}
