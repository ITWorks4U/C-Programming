#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_CHAR_AMOUNT	100

/*
	Usually, to copy a string you can use strcpy(), strncpy(), strcpy_s(), strncpy_s(), ...
	or you can write your own function instead.

	This example demonstrates you, how you >>could<< do this. => Depending on OS, machine, etc.
	the result may be different!
*/

void copy_my_string(char *destination, const char* source) {
	/*	What may happen, if source / destination or both are NULL?	*/
	if (source != NULL && destination != NULL) {
		int counter = 0;

		//	max amount of free characters for destination without \0
		size_t max_size_destination = strlen(destination);

		/*	We must not exceed the limit of destination and also for the source.	*/
		while(counter < max_size_destination && counter < strlen(source)) {
			if (source[counter] == '\0') {
				break;
			}

			destination[counter] = source[counter];
			counter++;
		}

		destination[counter] = '\0';

		/*
			Basicly, it's not required to return this C-string by using return destination,
			because in C you can't directly assign it to a C-string.
			Thus destination points to an address, where a C-string outside
			of this function now can access.
		*/
	}
}

int main(void) {
	char word[] = "Hello World!";
	char c_str[MAX_CHAR_AMOUNT];																					//	Remeber to have at least enough free space for your c_str!

	memset(c_str, '\0', MAX_CHAR_AMOUNT);																			//	best way to clear your C-string
																													//	by the way, that's OS independend
	printf("(%p <=> %s) c_str = %s\n", strcpy(c_str, word), strcpy(c_str, word), c_str);

	memset(c_str, '\0', MAX_CHAR_AMOUNT);
	copy_my_string(c_str, word);
	printf("(%p <=> %s) | (%p <=> %s)\n", word, word, c_str, c_str);

	return EXIT_SUCCESS;
}
