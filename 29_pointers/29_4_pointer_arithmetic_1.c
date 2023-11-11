#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
		pointer arithmetic means:	"incrementing / decrementing a pointer and see, which next value returns"
		Guess what? It's no guarantee, that this works always fine!

		Since a pointer has a known size of 8 bytes, this won't work with pointer arithmetic!
	*/

	int array[] = {0,1,2,3,4,5,6};
	int *ptr = array;

	printf("ptr = %d (array[0] = %d)\n", ptr[0], array[0]);
	ptr++;
	printf("ptr = %d (array[1] = %d)\n", ptr[0], array[1]);
	ptr++;
	printf("ptr = %d (array[2] = %d)\n", ptr[0], array[2]);
	ptr++;
	printf("ptr = %d (array[3] = %d)\n", ptr[0], array[3]);
	ptr++;
	//	........

	//	since ptr is a pointer, but used with malloc, calloc, ...
	//	free / delete causes a segmentation fault, because
	//	array AND ALSO ptr are stored on the stack, not on heap
	// free(ptr);

	/*
		Explanation:

		Since ptr[0] might means: "Show me the first element of array", it doesn't
		work with pointer arithmetic. With ptr++ we're using the next value in our
		array, thus ptr[0] points to the next known value.

		Be careful: By using an another pointer / array, an undefined behavior appears!
	*/

	return EXIT_SUCCESS;
}