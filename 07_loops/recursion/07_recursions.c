#include <stdio.h>
#include <stdlib.h>

//	-----------
//	allows to run the function again and again and again... and... again
//	Runs mostly faster than an iteration and has less content in contrast
//	to an iteration, however, you may have trouble when an error occurrs,
//	because it's hard to find a logical error.
//	-----------
int recursion_function(int counter) {
	if (counter >= 100) {
		return counter;
	}

	printf("counter = %d\n", counter);
	counter++;
	return recursion_function(counter);
}

int main() {
	printf("%d\n", recursion_function(0));
	return EXIT_SUCCESS;
}