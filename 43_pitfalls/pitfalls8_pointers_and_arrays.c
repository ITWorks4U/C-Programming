/*	In C / C++ you might assume, that pointers and arrays might be the same,
*	even some instructions are supported by both systems, but...
*
*	A pointer is never equal to an array.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array_0[] = {0,1,2,3,4,5,6,7,8,9};
	puts("----------------------------------");
	puts("array_0");
	puts("----------------------------------");
	for (int i = 0; i < 10; i++) {
		printf("array_0[%d] = %d\n", i, array_0[i]);
	}

	puts("----------------------------------");
	for(size_t i = 0; i < (sizeof(array_0) / sizeof(array_0[0])); i++) {
		printf("array_0[%lu] = %d\n", i, array_0[i]);
	}
	puts("----------------------------------");

	/*	even in the IDE this might be possible, a pointer can't be initialized with values
	*	a warning on compiling may appear or you'll get a compiler error
	*
	*	If you really got an output file, your application often crashes or might gives
	*	you unexpected data.
	*
	*	By the way, leaving a pointer uninitalized may also results into an undefined behavior.
	*/
	int *array_1 = {0,1,2,3,4,5,6,7,8,9};
	/* int *array_1; */

	puts("----------------------------------");
	puts("array_1");
	puts("----------------------------------");
	for (int i = 0; i < 10; i++) {
		printf("array_1[%d] = %d\n", i, array_1[i]);
	}

	puts("----------------------------------");
	for(size_t i = 0; i < (sizeof(array_1) / sizeof(array_1[0])); i++) {
		printf("array_1[%lu] = %d\n", i, array_1[i]);
	}
	puts("----------------------------------");

	return EXIT_FAILURE;
}