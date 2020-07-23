#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "02_threadSort.h"

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

void *bubbleSort(void *argument) {
	printf(" I'm thread number %ld\n", pthread_self());
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

	return NULL;
}

void failureOperation(const char *message) {
	perror(message);
	exit(EXIT_FAILURE);
}
