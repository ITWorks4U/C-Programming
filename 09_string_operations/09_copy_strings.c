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

	/*	Won't work in C!	*/
	//	word = fixed_expression;

	/*
		copying a text to an another C-string; doesn't handle buffer overflow
		char *strcpy(char *dest, const char *source);

		char *strncpy(char *dest, const char *source, size_t __n);
		copies n characters from source to destination; doesn't handle buffer overflow

		for Windows:
		use strcpy_s(), strncpy_s() instead
	*/
	strncpy(word, fixed_expression, strlen(fixed_expression));
	printf("word contains: %s\n", word);

	return EXIT_SUCCESS;
}