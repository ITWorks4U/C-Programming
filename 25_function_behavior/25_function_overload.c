#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>															//	accessing to functions, data types etc.

/*
	Honestly, "a function overload" doesn't exist
	in C programming, however, there's a way to handle
	this. Be careful, because you'll set up your
	trap for you own very easy, if you don't mind.
	If you really do, an undefined behavior may appear.

	We need at least one argument, which is required followed
	by any amount of any arguments.
*/

void function(int n, ...) {
	puts("---------");

	va_list vector;															//	defining a list (often called vector)
	va_start(vector, n);													//	initialize with given n arguments

	for(int i = 0; i < n; i++) {
		printf("%d\n", va_arg(vector, int));								//	output of arguments => given type may
																			//	cause an undefined behavior

		/*
			try to figure out, when you're using this:
			double,
			float,
			char,
			char *,
			void *
			>any data type here<

			=> va_arg(vector, >TYPE<);
		*/
	}

	va_end(vector);															//	remove vector from memory
}

int main(void) {
	/*	normal extended function calls	*/
	function(4, 500,600,700,800);											//	calling the function with 4
																			//	additional arguments

	function(0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0);								//	Surprise #1! :o)
	function(12.34, 0,1,2,3,4,5,6,7,8,9,10,11,12);							//	Surprise #2! :o)
	function('A', 1,2,3,4,5,6,7);											//	Surprise #3! :o)
	function(4, 'A', 'B', 'C', 'D');										//	Surprise #4! :o)

	/*	undefined behavior	*/
	function(100);															//	Ouch!
	function(5, "abc", "def", "ghi", "jkl", "mno");							//	you may get a warning or
																			//	an error on compile time

	return EXIT_SUCCESS;
}