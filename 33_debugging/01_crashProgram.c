/**
*	How to debug a C application with gdb.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

int divideNumbers(int nominator, int denominator);

int divideNumbers(int nominator, int denominator) {
	return (nominator / denominator);
}

int main() {
	int nbr01 = 8;
	int nbr02 = 2;

	/*	print the result to the console	*/
	printf(" %d/%d = %d\n", nbr01, nbr02, divideNumbers(nbr01, nbr02));

	puts(" ↓↓↓ The instruction below will crash the program.");
	nbr02 = 0;

	/*	it's not allowed to divide a number with 0, except by using rule of L'Hôpital	*/
	printf(" %d/%d = %d\n", nbr01, nbr02, divideNumbers(nbr01, nbr02));

	return EXIT_SUCCESS;
}
