#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Usually, to copy a string you can use strcpy(), ...,
	or you can write your own function instead.
	This example demonstrates you, how you >>could<<
	do this.
*/

char *my_string_copy(char *destination, const char* source) {
	if (source != NULL && destination != NULL) {														//	What really may happen,
																										//	if source / destination is / are both NULL?
		int counter = 0;
        size_t max_size_destination = strlen(destination);                                              //  max amount of free characters
                                                                                                        //  for destination without \0

        /*
            We must not exceed the limit of destination and also for the source.
        */
		while(counter < max_size_destination && counter < strlen(source)) {
			if (source[counter] == '\0') {
				break;
			}

			destination[counter] = source[counter];
			counter++;
		}

		destination[counter] = '\0';
		return destination;																				//	Basicly, it's not required to
																										//	to return this C-string, because
																										//	in C you can't directly assign
																										//	it to a C-string.
	}

	return NULL;                                                                                        //  default way, if a C-string is NULL
                                                                                                        //  to avoid to cause an undefined
                                                                                                        //  behavior
}

int main(void) {
	char word[] = "Hello World!";
	char c_str[100];																					//	What may happen, if we haven't
																										//	enough free space?

	memset(c_str, '\0', 100);																			//	best way to prepare your C-string
																										//	by the way, that's OS independend
	printf("(%p <=> %s) c_str = %s\n", strcpy(c_str, word), strcpy(c_str, word), c_str);

	memset(c_str, '\0', 100);
	printf("(%p <=> %s) c_str = %s\n", my_string_copy(c_str, word), my_string_copy(c_str, word), c_str);

	return EXIT_SUCCESS;
}
