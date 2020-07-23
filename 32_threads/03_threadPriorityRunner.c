#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "03_threadPriority.h"

int main() {
	int i;
	pthread_t th[NBR_OF_THREADS];

	printf(" starting main thread with ID %ld\n", pthread_self());

	for (i = 0; i < NBR_OF_THREADS; i++) {													/*	starting threads						*/
		if ((pthread_create(&th[i], NULL, threadPriorityDemoFunction, NULL)) != 0) {
			perror(" pthread_create()");
			return EXIT_FAILURE;
		}
	}

	for (i = 0; i < NBR_OF_THREADS; i++) {													/*	waiting for threads						*/
		if ((pthread_join(th[i], NULL)) != 0) {
			perror(" pthread_join()");
			return EXIT_FAILURE;
		}
	}

	printf(" terminating main thread with ID %ld\n", pthread_self());
	return EXIT_SUCCESS;
}
