#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "01_threads.h"

void *threadFunction(void *argument) {
	srand(time(NULL));
	int randomNumber = (rand() % 10 + 1);						/*	let's create a random number between 1 and 10	*/
	int i;
	printf(" → randomized number is %d\n", randomNumber);
	printf(" I'm thread number %ld\n", pthread_self());			/*	pthread_self(): receiving the current thread ID	*/

	for (i = 0; i < randomNumber; i++) {
		printf(" This is loop step number %d...\n", i);
		sleep(1);
	}	

	return NULL;
}

void failureOperation(const char *message) {
	perror(message);
	exit(EXIT_FAILURE);
}
