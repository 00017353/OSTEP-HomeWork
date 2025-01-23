#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    int child = fork();
    char *text = "Process Textb\n";
    write(fd, text, strlen(text));
}
