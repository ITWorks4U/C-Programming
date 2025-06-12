/*	In contrast to C++ a function in C has a different behavior by default.	*/

#include <stdio.h>
#include <stdlib.h>

/*	In C a function can be called with any number of arguments of any types.
*	By default a function is defined as <type> <function_name>(...);
*
*	Where "..." means: "Hey, you can use any amount of argument(s) of any type(s)."
*/
void function() {
	puts("Do something here...");
}

/*	To avoid to call a function with any number of arguments of any types, like
*	no argument is allowed, type void into the brackets, like main below.
*
*	Alternatively define a function with a fixed amount of argument(s) to force
*	the user to call a function with that amount and type(s) of argument(s) only.
*/
int main(void) {
	function();

	short a = 0;
	int b = 1;
	long c = 2;
	float d = 3.0F;
	double e = 4.0e-1234;
	char *f = NULL;
	function(a,b,c,d,e,f);

	function("Test that!", "Hello World!", "Oops, was this supposed to do?");

	return EXIT_FAILURE;
}