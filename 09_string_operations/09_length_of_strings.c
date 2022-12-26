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

int main() {
	char word[50];																//	C-string with up to 49 characters (last char: \0)!
	char fixed_expression[] = "A fixed expression for our purpose.";			//	fixed C-string with 36 characters (with \0)

	/*
		determine the length of a string:
		size_t strlen(const char *s);

		The strlen() function calculates the length of the string pointed to by s,
		excluding null terminating null byte ('\0').
	*/
	printf("word contains %lu characters\n", strlen(word));

	/*
		OFTEN USED, BUT THAT'S A HORRIBLE MISTAKE!
		sizeof() returns the maximum amount of possible storage for given C-string
	*/
	printf("word contains %lu characters\n", sizeof(word));

	return EXIT_SUCCESS;
}