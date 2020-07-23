/**
*	How to debug a C application with gdb.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

#define	NEW_NUMBER	255

void handleWithInteger(int *ptr, int value);

void handleWithInteger(int *ptr, int value) {
	*ptr = value;
}

int main() {
	int nbr01, nbr02;
	handleWithInteger(&nbr01, NEW_NUMBER);				/*	`&` := the address for integer type	*/
	printf(" nbr01 = %d\n", nbr01);

	puts(" ↓↓↓ The instruction below will crash the program.");
	handleWithInteger(nbr02, NEW_NUMBER);				/*	without `&` this program will crash	*/
	printf(" nbr02 = %d\n", nbr02);

	return EXIT_SUCCESS;
}
