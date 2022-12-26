#include <stdio.h>
#include <stdlib.h>

/*
	With gets() you're able to read any input from keyboard, however, it's strictly
	recommended NOT USING this function! The gets() function has no buffer overflow
	protection, therefore you can crash your application very easily.
*/

int main() {
	char single_sign;																				//	holds a single sign only
	char word[32];																					//	holds up to 31 characters including a null termination character \0
	char fixed_word[] = "A given string with a fixed length";										//	fixed word

	/*	reading from keyboard	*/
	printf("enter something: ");
	gets(word);

	/*	see, what happens:	*/
	printf("your input was: %s\n", word);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}