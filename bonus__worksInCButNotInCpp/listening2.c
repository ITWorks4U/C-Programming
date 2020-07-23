/*
 *	Create an undefined constant variable. In C the value of the constant
 *	variable may set to a default value, depending on it's type, but C++
 *	requires to initialize the constant variable.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	const long lVal;			//	an uninitialized constant value
	printf(" lVal = %lu\n", lVal);

	return EXIT_SUCCESS;
}
