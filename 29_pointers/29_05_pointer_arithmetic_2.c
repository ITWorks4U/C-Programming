#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
		pointer arithmetic means:	"incrementing / decrementing a pointer and see, which next value returns"
		Guess what? It's no guarantee, that this works always fine!

		Since a pointer has a known size of n bytes, depending on the machine, you're working on,
		this won't work with pointer arithmetic!
	*/

	char array[] = "Pointers aren't hard to use, right?";

	//	Not recommented to use an integer pointer for a c-string!
	int *ptr = (int *) array;

	printf("ptr = %d (array[0] = %c)\n", ptr[0], array[0]);
	ptr++;
	printf("ptr = %d (array[1] = %c)\n", ptr[0], array[1]);
	ptr++;
	printf("ptr = %d (array[2] = %c)\n", ptr[0], array[2]);
	ptr++;
	printf("ptr = %d (array[3] = %c)\n", ptr[0], array[3]);
	ptr++;
	//	........

	/*
		Explanation:

		Since ptr is an integer pointer and points to a c-string, this DOESN'T mean,
		that this sample above works "fine". ptr++ uses the next 4 BYTES (int), and
		the value of array[x] is going to transfer to an integer expression, however,
		array[0-3] represents ptr[0], array[4-7] ptr[1], ...

		=> printf("ptr = %d (array[0] = %c)\n", ptr[0], array[0]);
		doesn't prints "P (array[0] = P)"
	*/

	return EXIT_SUCCESS;
}