/*	Don't assume, that a variable increment is identical to a pointer increment.	*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int counter = 0;

	/*	points to the address of counter	*/
	int *counter_ptr = &counter;

	puts("----------------------------------");
	puts("before:");
	puts("----------------------------------");
	printf("counter = %d, address (and value): %p (%d)\n", counter, counter_ptr, *counter_ptr);
	puts("----------------------------------");

	/*	depending on which type for your pointer is in use, the incrementation "by one" also
	*	affects to increment the size of the type
	*
	*	e.g.: int => 4 btyes => "incrementing by 1" means: move the pointer by 4 bytes
	*/
	counter++;
	counter_ptr++;

	puts("----------------------------------");
	puts("after:");
	puts("----------------------------------");
	printf("counter = %d, address (and value): %p (%d)\n", counter, counter_ptr, *counter_ptr);
	puts("----------------------------------");

	return EXIT_FAILURE;
}