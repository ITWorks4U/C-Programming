#include <stdio.h>
#include <stdlib.h>

/*
	With fgets() you're able to read any input from keyboard, however, it will
	be interpreted as a set of words only. So you have to convert the input
	to the correct format. On the other hand you are able to scan multiple
	words as a single word.
	
	fgets() will read a maximum number of characters depending on your given
	limit. Finally, a newline will be automatically added to the string.
*/

int main() {
	char single_sign;																				//	holds a single sign only
	char word[32];																					//	holds up to 31 characters including a null termination character \0
	char fixed_word[] = "A given string with a fixed length";										//	fixed word
	int number;

	/*	reading from keyboard	*/
	printf("enter something: ");
	fgets(word, 32, stdin);																			//	reading up to 32 characters to word from keyboard (stdin); remember: every
																									//	C-string ends with a null termination character, so it may also crash your
																									//	application or any other issue, if there's no free space for a null
																									//	termination character

	/*	see, what happens:	*/
	printf("your input was: %s\n", word);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}