/*
	Usually, there're three different ways to define a constant expression:
	const, #define, using an anonymous enumeration.

	However, const doesn't really define a constant expression...
*/
#include <stdio.h>
#include <stdlib.h>

/*
	What happens, when you're using a pointer as an argument instead?
	Well, then you're also able to modify a "constant expression" very easily.

	Remember: without "const" to protect your argument, the original defined "i"
	will also be affected.
*/
void function(int *i) {
	printf("before: i = %d (%p)\n", i[0], i);
	*i = 0xBadFeed;
	printf("after: i = %d (%p)\n", i[0], i);
}

int main(void) {
	const int i = 100;

	puts("----------------------");
	function(&i);
	puts("----------------------");

	//	oops :o)
	printf("i = %d (%p)\n", i, &i);
	puts("----------------------");

	return EXIT_SUCCESS;
}