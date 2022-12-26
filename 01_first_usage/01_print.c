/*
	First impression by using printf() function
	to print any text on console.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	//	prints any text on console; attention: without a newline command: \n
	//	the promt line or the next output will be printed on the same line
	printf("This is our first text!\n");

	//	prints any text on console; unlike to printf() a newline is automatically
	//	added at the end of the text stream
	puts("Any text here.");

	//	using a variable and referencing a value to it
	int a = 7654321;

	//	%d is in use to print an integer value (int) as a formatted word on console
	//	int printf(const char *__restrict__ __format, ...) returns the number
	//	of written characters, so it's possible to refer a variable to it...
	int b = printf("a = %d\n", a);

	//	...however, the expected result differs to the real output...
	//	Can you figure out why?
	printf("b = %d characters\n", b);

	//	terminating the application on successfully way
	return EXIT_SUCCESS;
}
