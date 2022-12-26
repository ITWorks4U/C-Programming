/*
	Simple time measurement for C programming.
	In C++ you should use an another way.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>

void print_time(double seconds) {
	printf(
		"duration: %.lf h, %.lf min, %.lf s\n",
		floor(seconds / 3600), floor(seconds / 60), fmod(seconds, 60)
	);
}

int main() {
	char BUFFER[101];
	memset(BUFFER, '\0', 101);
	char word_to_copy[] = "This is a simple lext to copy.";
	unsigned int counter = 0;

	clock_t start_timer = clock();
	puts("starting time measurement...");

	while(counter != UINT_MAX) {
		counter++;
		strncpy(BUFFER, word_to_copy, strlen(word_to_copy));
	}

	puts("Finished!");
	clock_t end_timer = clock();
	print_time(((double)(end_timer - start_timer) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}