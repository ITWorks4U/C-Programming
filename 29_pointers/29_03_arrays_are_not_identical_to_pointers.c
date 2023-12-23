#include <stdio.h>
#include <stdlib.h>

/*	often misinterpreted:	"Arrays and pointers are the same, because these have a similar workflow."
	That's wrong. Even pointers and arrays are handled similar, an array always has a fixed knwon
	amount of elements of the type it refers.

	A pointer might looks like an array, however, you can attach n elements into it.
	Finally, it's not clear how to determine the number of elements, which shall be
	covered by the pointer, since a pointer still gives you an information, where the
	first elements has been stored, not every other element!
*/

int main(void) {
	//	an array has a fixed amount of elements
	int array[] = {1,2,3,4,5};

	/*	often a mistake:
		int array* = {1,2,3,4,5}

		This is NOT a definition of an array and also not a definition of a dynamic
		array with at least 5 elements, which can add much more elements during runtime.
	*/


	/*	(sizeof(array) / sizeof(array[0])) calculates the number of
		elements in the array; when you're using a pointer, then
		this won't work well. Since the size of a pointer differs
		on which machine you're working on, you can hardly calculate
		the number of elements with that.
	*/

	for(size_t i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
		printf("array[%lu]: %d\n", i, array[i]);
	}

	//	a pointer has no known amount of elements, even these are given
	//	it doesn't matter, if malloc, calloc, realloc, valloc, new, ... is used
	int *arrayPtr = malloc(sizeof(int) * 5);

	//	Are you surprised?
	for(size_t i = 0; i < (sizeof(arrayPtr) / sizeof(arrayPtr[0])); i++) {
		printf("arrayPtr[%lu]: %d\n", i, arrayPtr[i]);
	}

	free(arrayPtr);

	/*
		Explanation:

		An array has a fixed amount of elements. (sizeof(array) / sizeof(array[0]))
		calculates the full amount of bytes depending on the used type and divides
		it with the first element of the array (same type) => you may also use
		(sizeof(array) / sizeof(array[1])), (sizeof(array) / sizeof(array[2])), ...

		array[] comes with a memory amount of 20 bytes (4*5 bytes)

		A pointer has no known amunt of elements! It doesn't matter, if you're using
		a number of elements to use with. Since any pointer has ALWAYS a size of n bytes,
		depending on the machine you're working on.

		On a 64 bit machine the pointer has always a size of 8 bytes;
		(sizeof(arrayPtr) / sizeof(arrayPtr[0])) returns 2! => 8 (pointer) / 4 (int) = 2

		By the way, it doesn't matter, if you're using
		*arrayPtr, **arrayPtr, ..., *************************************************arrayPtr

		=> These pointers has a size of.... *drumrolls* 8 bytes!

		In that case you have to work with the known fixed number of elements:
		*arrayPtr = malloc(sizeof(int) * 5);
		for (int i = 0; i < 5; i++) {
			........
		}
	*/

	return EXIT_SUCCESS;
}