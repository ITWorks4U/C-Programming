#include <stdio.h>
#include <stdlib.h>

int main() {
	int counter = 0;

	//	-----------
	//	allows to jump to that mark, if called
	//	it's an "easy" implementation, however,
	//	it causes "spaghetti code", because it's
	//	much harder to debug in case of an error
	//	-----------
	mark:
	printf("counter = %d\n", counter);

	if (counter < 10) {
		//	-----------
		//	command to jump to a certain mark
		//	-----------
		goto mark;
	}

	return EXIT_SUCCESS;
}