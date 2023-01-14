#include <stdio.h>
#include <stdlib.h>

/*
	By defining a function with a void
	argument, we're no longer allowed to
	call the function with any amount of
	arguments for any type.

	However, by defining the void argument
	for the main function doesn't force
	you to call your application without
	any arguments only. You can still do this.
*/

void function(void) {
	puts("I was called!");
}

int main(void) {
	function();

	/*	are no longer able to call:

		function(123);
		function("abc");
		function(0,1,2,3,4,5,6,7,8,9);
		function("hello world", 54321, 753.964);

	*/

	return EXIT_SUCCESS;
}