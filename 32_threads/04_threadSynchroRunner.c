#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "04_threadSynchro.h"

int main() {
	pthread_t th1, th2;
	printf(" starting main thread %ld\n", pthread_self());
	
	if ((pthread_create(&th1, NULL, &writeIntoFile, NULL)) != 0) {
		perror(" pthread_create()");
		return EXIT_FAILURE;
	}

	if ((pthread_create(&th2, NULL, &readFromFile, NULL)) != 0) {
		perror(" pthread_create()");
		return EXIT_FAILURE;
	}

	if ((pthread_join(th1, NULL)) != 0) {
		perror(" pthread_join()");
		return EXIT_FAILURE;
	}

	if ((pthread_join(th2, NULL)) != 0) {
		perror(" pthread_join()");
		return EXIT_FAILURE;
	}

	printf(" finishing main thread %ld\n", pthread_self());
	return EXIT_SUCCESS;
}

