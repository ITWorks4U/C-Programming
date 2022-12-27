/*
	literals, mostly used in C,
	allows you to determine the
	correct form of a data type
	or value content
*/

#include <stdio.h>
#include <stdlib.h>

//	An IDE might interpret that value as a decimal integer.
//	Since a macro is typeless, this expectation is not always given.
#define		VALUE		1000

int main() {
	printf("value = %d\n", VALUE);

	/*	but it's not always a decimal value, like:	*/
	#undef	VALUE
	#define	VALUE		0x1000						//	hexadecimal integer
	printf("value = %d\n", VALUE);

	#undef	VALUE
	#define	VALUE		01000						//	octal integer
	printf("value = %d\n", VALUE);

	#undef	VALUE
	#define	VALUE		0B1000						//	hexadecimal integer
	printf("value = %d\n", VALUE);

	#undef	VALUE
	#define	VALUE		1000L						//	decimal long
	printf("value = %ld\n", VALUE);

	#undef	VALUE
	#define	VALUE		1000U						//	decimal unsigned integer
	printf("value = %u\n", VALUE);

	return EXIT_SUCCESS;
}