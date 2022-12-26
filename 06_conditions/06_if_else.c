#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	/*
		Usually, in C/C++ every condition check returns 0 for
		false, every other value is true! Typically the number
		range {0, 1} is used only.
	*/
	bool valueA = -100;

	if (valueA) {
		puts("This statement is \"true\"");
	} else {
		puts("This statement is \"false\"");
	}

	return EXIT_SUCCESS;
}