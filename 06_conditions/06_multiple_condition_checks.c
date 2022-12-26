#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	bool valueA = 100;
	bool valueB = 200;

	if (valueA >= 100 && valueB >= 100) {
		puts("This statement is \"true\"");
	}

	if (valueA && valueB) {																			//	identical to condition check above
		puts("This statement is \"true\"");
	}

	if (valueA >= 200 || valueB >= 200) {
		puts("This statement is \"true\"");
	}

	return EXIT_SUCCESS;
}