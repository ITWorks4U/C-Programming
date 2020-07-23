#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <assert.h>
#include "07_detach.h"

void *threadFunction(void *arg) {
	assert(arg != NULL);
	int *tmp = (int *) arg;
	int value = tmp[0];

	if ((value % 2) == 0) {													
		printf(" Thread %2d is detached.\n", value);								/*	it's an even number				*/
	} else {																
		printf(" Thread %2d is able to handle with pthread_join.\n", value);		/*	otherwise it's an odd number	*/
	}

	return NULL;
}

int main(void) {
	pthread_t th[NBR_OF_THREADS];
	int i;

	for (i = 0; i < NBR_OF_THREADS; i++) {
		if ((pthread_create(&th[i], NULL, threadFunction, (void *) &i)) != 0) {
			perror (" pthread_create");
			return EXIT_FAILURE;
		}

		if ((i % 2) == 0) {																/*	←	check, if `i` is an even or an odd number	*/
			/*
			 *	int pthread_detach(pthread_t thread) - detaching a thread
			 *
			 *	returns:		0, if no error occurred, -1 otherwise
			*/
			if ((pthread_detach(th[i])) != 0) {
				perror (" pthread_detach");
				return EXIT_FAILURE;
			}
		}

		sleep(1);
	}

	puts("\n **********\n");

	for (i = 0; i < NBR_OF_THREADS; i++) {
		if ((pthread_join(th[i], NULL)) != 0) {
			printf(" Thread %d joined.\n", i);
		} else {			
			printf(" thread %i has been detached before...\n", i);
		}
	}

	return EXIT_SUCCESS;
}
