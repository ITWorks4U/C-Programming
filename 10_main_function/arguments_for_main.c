/**
*	How to handle with given
*	arguments for the main program.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

/*	converting argv to numbers	*/
int main(int argc, char **argv) {
	int firstArgument;
	long secondArgument;
	double thirdArgument;

	/*	--- should not used anymore, because these functions below are unsafe	---
	firstArgument = atoi(argv[1]);
	secondArgument = atol(argv[2]);
	thirdArgument = atof(argv[3]);
	*/	

	/**
	*	long int strtol(const char *str, char **endptr, int base);
	*
	*	str			This is the string containing the representation of an integral number.
	*
	*	endptr		This is the reference to an object of type char*, whose value is set
	*				by the function to the next character in str after the numerical value.
	*
	*	base		This is the base, which must be between 2 and 36 inclusive,
	*				or be the special value 0.
	*/
	firstArgument = strol(argv[1], NULL, 0);
	secondArgument = strol(argv[2], NULL, 0);
	thirdArgument = strod(argv[3], NULL, 0);

	printf(" 1st argument as integer: %i\n 2nd argument as long: %ld\n 3rd argument as double: %lf\n",
		firstArgument, secondArgument, thirdArgument);

	return EXIT_SUCCESS;
}
