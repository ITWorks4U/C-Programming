#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
		pointer arithmetic means:	"incrementing / decrementing a pointer and see, which next value returns"
		Guess what? It's no guarantee, that this works always fine!

		Since a pointer has a known size of n bytes, depending on the machine, you're working on,
		this won't work with pointer arithmetic!
	*/

	int array[] = {0,1,2,3,4,5,6};

	//	Not recommented to use an c-string for an integer array!
	char *ptr = (char *) array;

	printf("ptr = %d (array[0] = %c)\n", ptr[0], array[0]);
	ptr++;
	printf("ptr = %d (array[1] = %c)\n", ptr[0], array[1]);
	ptr++;
	printf("ptr = %d (array[2] = %c)\n", ptr[0], array[2]);
	ptr++;
	printf("ptr = %d (array[3] = %c)\n", ptr[0], array[3]);
	ptr++;
	
	//	the next value can be read here:
	printf("ptr = %d (array[4] = %c)\n", ptr[0], array[4]);
	ptr++;
	printf("ptr = %d (array[5] = %c)\n", ptr[0], array[5]);
	ptr++;
	//	........

	/*
		Explanation:

		Have you expected to see:
		0 (array[0] = 0)
		1 (array[1] = 1)
		2 (array[2] = 2)
		3 (array[3] = 3) ?

		Well, now you know, you were wrong!
		
		Since ptr is a c-string the next value of ptr (ptr++) doesn't
		contain 1, because ptr++ walks only 1 byte! array is int, thus
		you're walking to the next byte of 4 bytes and trying to figure
		out which value MAY return.

		On every 4th step you might see the expected value, however,
		it's not clearly known, which values also returns.
	*/

	return EXIT_SUCCESS;
}