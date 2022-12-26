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
	//	word += fixed_expression;
	//	word = word + fixed_expression											//	will be interpreted as an addition of two numbers

	/*
		concatenation: adding a string to an another string 
		char *strcat(char *destination, const char *source);

		char *strncat(char *destination, const char *source, size_t __n);
		adding n characters from source to destination; doesn't handle buffer overflow

		for Windows:
		use strcat_s() / strncat_s() instead
	*/
	strncat(word, fixed_expression, strlen(fixed_expression));
	printf("word contains: %s\n", word);

	return EXIT_SUCCESS;
}