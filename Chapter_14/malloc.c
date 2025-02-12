#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char *mem = (char *)malloc(1000*1024*1024);
	for (int i=0; i<1000*1024*1024;i+=4096) {
		mem[i] = 0;
	}
	return 0;
}