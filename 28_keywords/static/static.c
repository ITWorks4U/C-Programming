#include <stdio.h>
#include <stdlib.h>

/*
	The static keyword in C is a storage-class specifier.
	It has different meanings, depending on the context.

	Inside a function it makes a variable to retain it's value
	between multiple function calls.

	Outside of a function it retains the visibility of the
	function or variable to the current file only.
*/

static int value = 100;																			//	often used for global declarations
																								//	to ensure, that this value is only
																								//	visible in this source file only

void without_static(void) {																		//	usually, in a function every variable
	int value_a = 0;																			//	will be automatically removed from the
	printf("without static: %d\n", ++value_a);													//	memory, when the function is left
}

void with_static(void) {																		//	unless, a variable is defined with static
	static int value_a = 0;																		//	this is won't be removed from the memory,
	printf("with static: %d\n", ++value_a);														//	thus value_a can be used more often
}

int main(void) {
	for(int i = 0; i < 10; i++) {
		without_static();
		with_static();
	}

	return EXIT_SUCCESS;
}