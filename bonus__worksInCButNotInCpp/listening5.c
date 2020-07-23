/*
 *	Try to point to a constant variable.
 *	It's allowed in C, but it not in C++.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	const int cVar = 127;
	int *iPtr = &cVar;				//	create a normal pointer to a constant variable

	printf(" cVar = %d, located on memory address: %p\n", cVar, iPtr);

	*iPtr = 0x1424ABF;				//	modify a constant value
	printf(" cVar = %d, located on memory address: %p\n", cVar, iPtr);

	return EXIT_SUCCESS;
}
