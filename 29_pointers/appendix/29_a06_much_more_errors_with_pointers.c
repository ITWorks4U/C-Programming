#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_CHARS	10000
static const char word[] = "Hello World!";

int main() {

	/*	What will happen, if you're assigning an empty word to a char pointer?
	 *	And what will happen, if you're using (char *) malloc((sizeof(char) + MAX_CHARS)) instead?
	*/
	char *input = "";
	printf("size of input: %lu bytes, location of input: %p\n", sizeof(input), input);

/*
	Reading from a keyboard or from a file
	required to store the current content
	to a buffer, often used a C-string.

	Try to figure out by using a different
	way for reading from keyboard. :o)
*/

	/*	using scanf() function	*/
	scanf(" %s", input);
	printf("value of input: %s\n", input);

	/*	using fgets() function	*/
	fgets(input, MAX_CHARS, stdin);
	printf("value of input: %s\n", input);

	/*	using strncpy() function	*/
	strncpy(input, word, strlen(word));
	printf("value of input: %s\n", input);

	/*	Since input is defined as "char *input" without using malloc, calloc, new, ...,
		it's not stored on the heap, it's on the stack, thus the free function
		below will cause a segmentation fault on runtime!
	 */
	// free(input);

	return EXIT_SUCCESS;
}