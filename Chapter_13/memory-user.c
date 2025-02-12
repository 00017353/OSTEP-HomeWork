#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		printf("Provide a size!\n");
		return 1;
	}

	size_t bytes = atoi(argv[1])*1024*1024;
	char * memory = malloc(bytes);

	while (1) {
		for (int i=0;i < bytes;i+=4096) {
			memory[i] = 0;	
		}
		usleep(10000);
	}	

	free(memory);
	return 0;
}