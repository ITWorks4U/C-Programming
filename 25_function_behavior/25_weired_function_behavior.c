#include <stdio.h>
#include <stdlib.h>

/*
	Usually, this function below can be called without
	arguments only, however, in C this works different.

	Because a function without an argument is differently
	defined. Instead of >void< it contains >...<, thus
	you're able to run this function in any way.

	By default, the three dots are invisible and you can't
	define the function with the dots only.

	The same procedure occurs for the main function.
*/

void function() {
	puts("I was called!");
}

int main() {
	function();
	function(123);
	function("abc");
	function(0,1,2,3,4,5,6,7,8,9);
	function("hello world", 54321, 753.964);

	return EXIT_SUCCESS;
}