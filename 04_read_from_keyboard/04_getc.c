#include <stdio.h>
#include <stdlib.h>

/*
	You're also able to read a single sign from keyboard by using one of
	these functions: getc(), fgetc(), getchar(), getch(). The single sign
	will be converted as an integer and can't be referenced to a C-string!
*/

int main() {
	char single_sign;																				//	holds a single sign only
	char word[32];																					//	holds up to 31 characters including a null termination character \0
	char fixed_word[] = "A given string with a fixed length";										//	fixed word
	int number;

	/*	reading from keyboard	*/
	printf("enter something: ");
	getc(stdin);																					//	reading from a string (stdin: keyboard)
	fgetc(stdin);																					//	better handling in contrast to getc()
	getchar();																						//	reading a single character from keyboard (stdin is fixed)
	// getch();																						//	often used on Windows and turbo C

	/*	see, what happens:	*/
	printf("your input was: %s\n", word);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}