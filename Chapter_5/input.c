#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    printf("You entered: %s", buffer);
}