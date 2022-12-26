#include <stdio.h>
#include <stdlib.h>
#include <limits.h>																							//	enables limits for basic data types
#include <float.h>																							//	enables limits for floating data types

int main() {
	//	CHAR_MIN, CHAR_MAX, ... are macros and contains defined ranges for certain
	//	data type
	printf("limit of char: %d <-> %d\n", CHAR_MIN, CHAR_MAX);
	printf("limit of short: %d <-> %d\n", SHRT_MIN, SHRT_MAX);
	printf("limit of int: %d <-> %d\n", INT_MIN, INT_MAX);
	printf("limit of long: %ld <-> %ld\n", LONG_MIN, LONG_MAX);
	printf("limit of long long: %lld <-> %lld\n", LLONG_MIN, LLONG_MAX);									//	identical to long int and long long int

	printf("limit of float: %e <-> %e\n", FLT_MIN, FLT_MAX);												//	%e => expotential value; much more better
	printf("limit of double: %E <-> %E\n", DBL_MIN, DBL_MAX);												//	than %f (float) or %lf (long float)

	printf("limit of unsigned char: %d <-> %u\n", 0, UCHAR_MAX);											//	minimal value starts on 0
	printf("limit of unsigned short: %d <-> %u\n", 0, USHRT_MAX);
	printf("limit of unsigned int: %d <-> %u\n", 0, UINT_MAX);
	printf("limit of unsigned long: %d <-> %lu\n", 0, ULONG_MAX);
	printf("limit of unsigned long long: %d <-> %llu\n", 0, ULLONG_MAX);

	//	under and overflow of datatypes; these won't be a critical error, in most cases,
	//	however, it's a 'simple' logical error
	printf("limit of int: %d <-> %d\n", INT_MIN - 1, INT_MAX + 1);

	return EXIT_SUCCESS;
}