#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 15

int main() {
	/*	fgets(): read complete line from keyboard or any stream; adds a '\n' to the the end.	*/
	char word[LENGTH];
	fgets(word, LENGTH, stdin);

	int i;
	for (i = 0; i < LENGTH; i++) {
		printf(" character %i as sign %c and as integer %d\n", i, word[i], (int) word[i]);		
	}
	printf("\n\n preplacing new line character with zero terminating character\n\n");

	/*	replace '\n' to '\0'	*/
	size_t wordLength = strlen(word);
	word[wordLength - 1] = '\0';
	
	for (i = 0; i < LENGTH; i++) {
		printf(" character %i as sign %c and as integer %d\n", i, word[i], (int) word[i]);		
	}


	/*	unlike to print required informations for anything on console by using printf(),
	*	move it to a string by using sprintf(char *str, const char *format, ...)
	*/

	printf("\n\n using sprintf(char *str, const char *format, ...)\n\n");
	char INFO[LENGTH];
	sprintf(INFO, "%i||%c||%d", 10, word[10], (int) word[10]);
	printf(" %s\n", INFO);
	printf("\n\n");

	
	/*	convert a string to an integer, if possible: long int strtol(const char *str, char **endptr, int base)
	*	deprecated function to convert a string to an integer: int atoi(const char *str)
	*/

	char *BUFFER;
	int number = strtol(INFO, &BUFFER, 8);
	printf(" Your number contains %d, where your BUFFER contains %s\n", number, BUFFER);

	return EXIT_SUCCESS;
}
