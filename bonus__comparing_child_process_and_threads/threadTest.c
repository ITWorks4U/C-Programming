#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "threadTest.h"

void *nonsenseFunction(void *args) {
	srand(time(NULL));
	//printf(" random number = %d\n", rand());

	return NULL;
}

int main(int argc, char **argv) {
	int i;
	clock_t start = clock();
	pthread_t th[NBR_OF_THREADS];
	printf(" Demonstration of using %d threads.\n", NBR_OF_THREADS);

	for (i = 0; i < NBR_OF_THREADS; i++) {
		if ((pthread_create(&th[i], NULL, nonsenseFunction, NULL)) != 0) {
			perror(" pthread_create");
		}
	}

	for (i = 0; i < NBR_OF_THREADS; i++) {
		if ((pthread_join(th[i], NULL)) != 0) {
			perror(" pthread_join");
		}
	}

	clock_t end = clock();
	double runningTime = ((double) (end - start) / CLOCKS_PER_SEC);

	int minutes = ((int) runningTime / MINUTES);
	int seconds = ((int) runningTime % (minutes * MINUTES));

	printf(" Elapsed time for program \"%s\": %2d minutes, %2d seconds.\n", argv[0], minutes, seconds);	

	return EXIT_SUCCESS;
}
