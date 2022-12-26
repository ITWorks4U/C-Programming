#include <stdio.h>
#include <stdlib.h>

/*
	With scanf() you're able to read any input from keyboard, however, you should
	know which input refers to which variable. By detecting a space bar the next
	input will be stored to the next free variable, so if you're using a text with
	two or more words, then this function doesn't handle it well.
*/

int main() {
	char single_sign;																				//	holds a single sign only
	char word[32];																					//	holds up to 31 characters including a null termination character \0
	char fixed_word[] = "A given string with a fixed length";										//	fixed word
	int number;

	/*	reading from keyboard	*/
	printf("enter something: ");
	scanf("%s %d", word, &number);																	//	advantage: you can handle different variables at the same time
																									//	disadvantage: the order of words must be identical to the scanned formats 

	/*	see, what happens:	*/
	printf("your input was: %s\n", word);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}