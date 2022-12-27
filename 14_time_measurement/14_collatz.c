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

unsigned long long collatz_conjecture(unsigned long long number) {
	printf("current number: %llu\n", number);
	step_ctr++;

	if (number % 2 == 0) {																//	number is even
		return collatz_conjecture(number / 2);
	} else if (number != 1 && number % 2 != 0) {										//	number is odd (except for 1)
		return collatz_conjecture(3 * number + 1);
	}

	return 1;																			//	for 1 only
}

int main() {
	clock_t start_timer = clock();
	puts("starting time measurement...");

	unsigned long long UPPER_BOUNDARY = ULLONG_MAX;
	collatz_conjecture(UPPER_BOUNDARY);
	printf("For %llu it tooks %d steps.\n", UPPER_BOUNDARY, step_ctr);
	puts("Finished!");
	clock_t end_timer = clock();
	print_time(((double)(end_timer - start_timer) / CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}