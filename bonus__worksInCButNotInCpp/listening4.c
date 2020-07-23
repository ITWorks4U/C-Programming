/*
 *	Append to a function n parameters. Works in C, but not in C++,
 *	because in C a function() is the same as function(...), where you may add
 *	n parameters. In C++ a function() is defined as function(void).
 *
 *	To avoid to add any parameters to a function in C, just change the definition
 *	of the function() to function(void).
*/

#include <stdio.h>
#include <stdlib.h>

int function();														/*	the function prototype	*/

int main() {
	int retVal = function();										/*	a normal function call	*/
	printf(" retVal = %d\n", retVal);

	retVal = function(1, 2, &retVal, "127.0.0.1", 1234.56789f);		/*	calling a function with n parameters; works in C, but not in C++	*/
	printf(" retVal = %d\n", retVal);

	return EXIT_SUCCESS;
}

int function() {
	/*	do something	*/
	return 1;
}
