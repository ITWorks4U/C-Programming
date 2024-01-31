/*
	Regular expressions might be hard to understand, however, this is a well made
	way to check an expression against a filter.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
		Read from keyboard and check, if the input is a number.

		Really stupid and primitive way:
			It may work for positive integers well, however, what happens,
			if you're using a floating point expression,
			hexadecimal expression, ...?

			Of course, it won't work (well). You also might cause an
			undefined behavior on runtime.
	*/
	int tmp;

	printf("enter a number: ");
	int ret = scanf("%d", &tmp);

	printf("given input \"%d\"... ", tmp);

	if (ret/*tmp*/ == 0) {
		puts("was not a number");
	} else {
		puts("was a number");
	}

	return EXIT_SUCCESS;
}