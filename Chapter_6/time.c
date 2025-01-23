#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>

int main() {
    int fd = open("/dev/null", O_RDONLY);
    int iterations = 1000000;
    struct timeval time_before, time_after;

    gettimeofday(&time_before, NULL);
    for(int i=0; i < iterations; i++) {
        read(fd, NULL, 0);
    }
    gettimeofday(&time_after, NULL);
    
    long difference = (time_after.tv_sec - time_before.tv_sec)*1000000 + (time_after.tv_usec - time_before.tv_usec); 
    double total_time = (double)difference / iterations;
    printf("Syscall read() takes %f microseconds on average to complete.\n", total_time);
    return 0;
}