#include <stdio.h>
#include <stdlib.h>

/*
	With atoi() (argument to integer), atol(), atof(), ... you can try to convert the given
	word to an integer, long, float, ... , howver, these functions have no buffer overflow
	detection and no error on compile time appears when a wrong format is in use.

	Use strtol(), strtod(), ... functions instead. strtol() := string to long,
	strtod() := string to double, ...

	With these functions you're able to handle any input left, which wasn't able to
	convert to the correct data type.
*/

int main() {
	long number;
	// number = atol("100");																					//	"may" convert the string to a long value,
	// number = atol("123I don't know.");																		//	however, this won't work well => undefined behavior
	number = strtol("123Idon't know", NULL, 10);

	/*
		long strtol(const char *__restrict__ __nptr, char **__restruct__ __endptr, int __base);
		__nptr 		:=		source to read and trying to convert to a long value
		__endptr 	:=		if given, any other character, which doesn't fit to long data type can be stored elsewhere; NULL: discard the input left
		__base 		:=		determine in which kind of format the number is going to read; 0: decimal, 2: bindary, 8: octal, 10: decimal, 16: hexadecimal
	*/

	printf("number contains: %ld\n", number);

	return EXIT_SUCCESS;
}