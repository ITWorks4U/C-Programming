/*
	Usually, there're three different ways to define a constant expression:
	const, #define, using an anonymous enumeration.

	However, const doesn't really define a constant expression...

	By the way, this has been tested in C only!
	It might also work in C++, but it also may result to a different (undefined) behavior.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//	usually, const "defines" a constant expression, so...
	const int i = 100;

	//	...this command below is not allowed as expected
	//i = 101;

	//	however, by using pointers you're able to use a back door with different results
	int *ptrForI = &i;

	puts("----------------------");

	//	scenario 1: pointer arithmetic
	printf("before: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
	ptrForI++;
	printf("after: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
	ptrForI = NULL;

	/*	As you can see, "i" has still the defined value, but you can
		also do this instead:
	*/

	puts("----------------------");

	//	scenario 2: refer an another memory address to the pointer
	ptrForI = &i;
	printf("before: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
	*ptrForI = 0xbeef3000;
	printf("after: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
	ptrForI = NULL;

	/*
		Unlike to the first scenario by refering to any memory address
		the "constant expression" has also been modified, even the pointer address
		is still the same!
	*/

	puts("----------------------");
	
	return EXIT_SUCCESS;
}