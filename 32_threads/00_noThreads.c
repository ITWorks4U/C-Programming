#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "00_noThreads.h"

static int array[NBR_OF_ELEMENTS];

void fillArrayWithElements() {
	srand(time(NULL));

	int i;
	for (i = 0; i < NBR_OF_ELEMENTS; i++) {
		array[i] = ((rand() % NBR_OF_ELEMENTS) + 1);
	}
}

void resetArray() {
	int i;
	for (i = 0; i < NBR_OF_ELEMENTS; i++) {
		array[i] = 0;
	}
}

void bubbleSort() {
	int i,j;

	for (i = 0; i < NBR_OF_ELEMENTS; i++) {
		for (j = (NBR_OF_ELEMENTS - 1); j >= 0; j--) {
			if (array[j-1] > array[j]) {
				int swap = array[j];
				array[j] = array[j-1];
				array[j-1] = swap;
			}
		}
	}
}

int main(int argc, char **argv) {
	int i;
	clock_t start = clock();

	printf(" Demonstration of bubble sort with %u elements without using threads.\n", NBR_OF_ELEMENTS);
	for (i = 0; i < 4; i++) {
		fillArrayWithElements();
		bubbleSort();
		resetArray();
	}

	clock_t end = clock();
	double runningTime = ((double) (end - start) / CLOCKS_PER_SEC);

	int minutes = ((int) runningTime / MINUTES);
	int seconds = ((int) runningTime % (minutes * MINUTES));

	printf(" Elapsed time for program \"%s\": %2d minutes, %2d seconds.\n", argv[0], minutes, seconds);	

	return EXIT_SUCCESS;
}
