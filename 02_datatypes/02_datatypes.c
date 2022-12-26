/*
	printing the amount of bytes for each known basic data type in C
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	//	sizeof(<type>) allows you to determine how many bytes
	//	the given type needs on your system, however, this
	//	won't work everywhere
	printf("char has a size of %lu bytes\n", sizeof(char));
	printf("short has a size of %lu bytes\n", sizeof(short));
	printf("short int has a size of %lu bytes\n", sizeof(short int));
	printf("int has a size of %lu bytes\n", sizeof(int));
	printf("long has a size of %lu bytes\n", sizeof(long));
	printf("long int has a size of %lu bytes\n", sizeof(long int));
	printf("long long has a size of %lu bytes\n", sizeof(long long));
	printf("long long int has a size of %lu bytes\n", sizeof(long long int));

	//	in C (also in C++) allows you to use signed and also
	//	unsigned datatypes
	printf("unsigned char has a size of %lu bytes\n", sizeof(unsigned char));
	printf("unsigned short has a size of %lu bytes\n", sizeof(unsigned short));
	printf("unsigned short int has a size of %lu bytes\n", sizeof(unsigned short int));
	printf("unsigned int has a size of %lu bytes\n", sizeof(unsigned int));
	printf("unsigned long has a size of %lu bytes\n", sizeof(unsigned long));
	printf("unsigned long int has a size of %lu bytes\n", sizeof(unsigned long int));
	printf("unsigned long long has a size of %lu bytes\n", sizeof(unsigned long long));
	printf("unsigned long long int has a size of %lu bytes\n", sizeof(unsigned long long int));

	/*
		note: (unsigned) short int, (unsigned) long int, (unsigned) long long int
		are rareley used and are often the same as (unsigned) short, (unsigned) long,
		(unsigned) long long
	*/

	//	using floating point data types; these aren't coming with unsigned, because it's not defined there
	printf("float has a size of %lu bytes\n", sizeof(float));
	printf("double has a size of %lu bytes\n", sizeof(double));

	return EXIT_SUCCESS;
}