/*	source file with required functions	*/

#include "34_threads.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <limits.h>

long test_array1[MAXIMUM];
long test_array2[MAXIMUM];

/// @brief printing time amount
/// @param seconds elapsed seconds
void print_time(double seconds) {
	double hours = floor(seconds / 3600);
	double minutes = floor(seconds / 60);
	seconds = fmod(seconds, 60);

	if (seconds >= 60) {
		seconds = fmod(seconds, 60);
		minutes++;
	}

	if (minutes >= 60) {
		minutes = fmod(minutes, 60);
		hours++;
	}

	printf("time amount: %.lf h, %.lf min, %.lf s\n", hours, minutes, seconds);
}

/// @brief load file with random numbers
void load_random_numbers(void) {
	char content_random_numbers[MAXIMUM];
	memset(content_random_numbers, '\0', sizeof(content_random_numbers));

	FILE *f = fopen(FILE_SOURCE, "r");
	while ((fgets(content_random_numbers, MAXIMUM, f)) != NULL) {}
	fclose(f);

	char delimiter[] = ", ";
	char* token = strtok(content_random_numbers, delimiter);
	int ctr = 0;

	while (token != NULL) {
		test_array1[ctr] = strtol(token, NULL, 0);
		test_array2[ctr] = strtol(token, NULL, 0);
		ctr++;

		token = strtok(NULL, delimiter);
	}
}

/// @brief a simple bubble sort
/// @param array array of elements to sort
void bubble_sort(long *array) {
	clock_t begin = clock();

	for(int i = 0; i < MAXIMUM - 1; i++) {
		for(int j = 0; j < MAXIMUM - i - 1; j++) {
			if (array[i] > array[j]) {
				long tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

	clock_t end = clock();
	print_time(((double)(end - begin) / CLOCKS_PER_SEC));
}

void print_first_results(const long *array) {
	for(int i = 15; i >= 0; i--) {
		printf("%ld, ", array[i]);
	}

	puts("...");
}