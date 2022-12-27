/*
	Simple time measurement for C programming.
	In C++ you should use an another way.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>

static int step_ctr = 0;

void print_time(double seconds) {
	printf(
		"duration: %.lf h, %.lf min, %.lf s\n",
		floor(seconds / 3600), floor(seconds / 60), fmod(seconds, 60)
	);
}

unsigned long long fibonacci_recursive(unsigned long long number) {							//	never use this function for large numbers
																							//	unless you can spend a huge amount of time :o)

	/*	May also crash your application of not enough free memory!	*/

	step_ctr++;
	/*	F(n) = F(n-1) + F(n-2)	*/
	if (number != 1) {
		return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
	}

	return 1;
}

int main() {
	clock_t start_timer = clock();
	puts("starting time measurement...");

	unsigned long long UPPER_BOUNDARY = 100;												//	even this "small" number might be too much
																							//	for the recursion function
	printf(
		"F(%llu) = %llu (it tooks %d steps)\n",
		UPPER_BOUNDARY, fibonacci_recursive(UPPER_BOUNDARY), step_ctr
	);

	puts("Finished!");
	clock_t end_timer = clock();
	print_time(((double)(end_timer - start_timer) / CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}