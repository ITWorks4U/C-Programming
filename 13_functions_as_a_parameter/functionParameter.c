/**
*	How to use a function as a parameter.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

/*	two function prototypes	*/
void printFunctionOne(int n);
void printFunctionTwo(int n);

/*	A function with a function as a parameter,
*	where this function holds also a parameter
*	of type int.
*/
void functionParameter(void (*f)(int));

/*	implementation of these functions like...	*/
void printFunctionOne(int n) {
	printf(" Gotten parameter: %d\n", n);
}

void printFunctionTwo(int n) {
	int i;
	for (i = 1; i < 11; i++) {
		printf(" %d + %d = %d\n", n, i, (n+i));
	}	
}

void functionParameter(void (*f)(int)) {
	int i;
	for (i = 0; i < 5; i++) {
		(*f)(i);
	}
}

int main() {
	//functionParameter(printFunctionOne);
	functionParameter(printFunctionTwo);

	return EXIT_SUCCESS;
}
