#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include "08_cancel_thread.h"

unsigned int createRandomNumber() {
	srand(time(NULL));
	return (rand() % (NBR_OF_THREADS + 1));
}

void *threadFunction(void *arg) {
	unsigned int randNbr = createRandomNumber();
	if (randNbr % 2 == 0) {								/*	cancel the current thread, if randNbr is an even number	*/
		printf(" → random number: %d | cancelling thread (%ld)...\n", randNbr, pthread_self());

		/*
		 *	int pthread_setcanceltype(int __type, int *__oldtype);
		 *
		 *	Set cancellation state of current thread to TYPE, returning the old
   		 *	type in *OLDTYPE if OLDTYPE is not NULL.
		 *
		 *	returns:	0, no error occurred,
	 	 *				-1, otherwise
		*/
		pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

		/*
		 *	int pthread_cancel(pthread_t thread);
		 *
		 *	Cancel THREAD immediately or at the next possibility.
		 *
		 *	returns:	0, no error occurred
		 *				-1 otherwise
		*/
		pthread_cancel(pthread_self());
	}

	printf(" Given thread (%ld) had number %d...\n", pthread_self(), randNbr);
	return NULL;
}

int main(void) {
	pthread_t th[NBR_OF_THREADS];
	int i, ctr;

	for (i = 0; i < NBR_OF_THREADS; i++) {
		pthread_create(&th[i], NULL, threadFunction, NULL);
		sleep(1);
	}

	for (i = 0; i < NBR_OF_THREADS; i++) {
		if ((pthread_join(th[i], NULL)) != 0) {
			perror(" pthread_join()");
			return EXIT_FAILURE;
		} else {
			ctr++;
		}
	}

	printf("\n *******\n Collected %d threads.\n", ctr);

	return EXIT_SUCCESS;
}
