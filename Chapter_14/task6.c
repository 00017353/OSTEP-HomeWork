#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *arr = (int *)malloc(10*sizeof(int));
	printf("arr: %p\n", arr);
	arr[5] = 123;
	printf("arr[5]: %d\n", arr[5]);
	free(arr);
	printf("arr freed!\n");
	int *arr2 = (int *)malloc(10*sizeof(int));
	printf("arr2: %p\n", arr2);
	printf("arr2[5]: %d\n", arr2[5]);
	return 0;
}