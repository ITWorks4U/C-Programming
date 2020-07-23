/**
*	How to define and use a function
*	with n arguments in C/C++.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>			/*	to use for va_list, va_start, va_arg, va_end	*/

double calculateAverageOf(int nbrOfArguments, ...);

int main() {
	printf(" A typical printf()-function.\n");
	printf(" A typical printf()-function with parameter %d of type \"int\".\n\n", 10);

	printf(" Average of 2,3,5,7,11,13,17,19 = %lf\n", calculateAverageOf(9, 2, 3, 5, 7, 11, 13, 17, 19));
	printf(" Average of 10,20,30 = %lf\n", calculateAverageOf(3, 10, 20, 30));

	return EXIT_SUCCESS;
}

double calculateAverageOf(int nbrOfArguments, ...) {
	va_list list;
	double average = 0.0F;
	int i;

	/*	initializing list with given number
	*	of arguments and given arguments, too
	*/
	va_start(list, nbrOfArguments);

	/*	let calculate the average of given arguments	*/
	for (i = 0; i < nbrOfArguments; i++) {
		average = average + va_arg(list, int);
	}

	/*	clean up memory for reserved list	*/
	va_end(list);

	return (average / nbrOfArguments);
}
