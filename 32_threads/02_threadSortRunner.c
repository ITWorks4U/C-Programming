#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "02_threadSort.h"

int main(int argc, char **argv) {
	int i;
	clock_t start = clock();
	pthread_t th[NBR_OF_THREADS];
	printf(" main thread with ID %ld is launching...\n", pthread_self());

	/*	starting threads	*/
	printf(" Demonstration of bubble sort with %u elements by using %u threads.\n", NBR_OF_ELEMENTS, NBR_OF_THREADS);
	for (i = 0; i < NBR_OF_THREADS; i++) {
		fillArrayWithElements();
		if ((pthread_create(&th[i], NULL, bubbleSort, NULL)) != 0) {
			failureOperation(" pthread_create");
		}
	}

	/*	waiting for threads	*/
	for (i = 0; i < NBR_OF_THREADS; i++) {
		resetArray();

		if ((pthread_join(th[i], NULL)) != 0) {
			failureOperation(" pthread_join");
		}
	}

	clock_t end = clock();
	double runningTime = ((double) (end - start) / CLOCKS_PER_SEC);

	int minutes = ((int) runningTime / MINUTES);
	int seconds = ((int) runningTime % (minutes * MINUTES));

	printf(" Elapsed time for program \"%s\": %2d minutes, %2d seconds.\n", argv[0], minutes, seconds);	

	return EXIT_SUCCESS;
}
