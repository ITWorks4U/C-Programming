/*
	Working with strings in C.
	It's difficult in contrast to other
	programming languages, because in C
	a string will be handled in a different way.

	It's not recommended to run this code under C++,
	because it may cause to crash the application!

	It's also recommended not to run this code under
	Windows, because Windows prefers to run the latest
	functions, whereas these functions are VERY old!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>																//	contains functions for C-strings
#include <strings.h>															//	contains additional functions for C-strings

int main() {
	char word[50];																//	C-string with up to 49 characters (last char: \0)!
	char fixed_expression[] = "A fixed expression for our purpose.";			//	fixed C-string with 36 characters (with \0)

	/*	May work in C, but that's not recommended!	*/
	// if (word != fixed_expression) {
	// 	puts("c-Strings are different.");
	// } else {
	// 	puts("c-Strings are equal.");
	// }

	/*
		comparing two C-strings to each other
		int strcmp(char *s1, char *s2);

		returns:
		< 0		:=		s1 is smaller than s2
		0		:=		s1 is equal to s2
		> 0		:=		s1 is greater than s2

		int strncmp(char *s1, char *s2, size_t __n);
		compares two C-strings up to n characters

		for Windows:
		use strcmp_s() instead
	*/
	printf("%d\n", strcmp(word, fixed_expression));								//	don't expect a useful result

	/*	using a function from strings.h		*/
	printf("%d\n", strcasecmp(word, fixed_expression));							//	ignoring case formatting; result differs to above

	return EXIT_SUCCESS;
}