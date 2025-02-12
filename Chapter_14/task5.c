#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *data = (int *)malloc(100*sizeof(int));
	data[99] = 0;
	return 0;
}