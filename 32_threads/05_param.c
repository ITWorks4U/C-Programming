#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include "05_param.h"

unsigned int createANewRandomNumber(int nbr) {
	srand(time(NULL));
	return (rand() % 1000 + nbr);			/*	returning a random number between nbr and 1000			*/
}

void *threadFunction(void *argument) {
	assert(argument != NULL);

	int *value = (int *) argument;			/*	convert the argument into a type of an integer pointer	*/
	int content = value[0];					/*	←	access to the real value							*/
	//int content = *value;					/*	←	works, too											*/

	switch(content) {
		case 0:
			printf(" first thread (%ld) got the random number: %u\n", pthread_self(), createANewRandomNumber(content));
			break;
		case 1:
			printf(" second thread (%ld) got the random number: %u\n", pthread_self(), createANewRandomNumber(content));
			break;
		case 2:
			printf(" third thread (%ld) got the random number: %u\n", pthread_self(), createANewRandomNumber(content));
			break;
		case 3:
			printf(" fourth thread (%ld) got the random number: %u\n", pthread_self(), createANewRandomNumber(content));
			break;
		default:
			printf(" Something went wrong with thread (%ld)...\n", pthread_self());
	}

	return NULL;
}

int main(void) {
	pthread_t threads[NBR_OF_THREADS];
	int i;

	for (i = 0; i < NBR_OF_THREADS; i++) {
		if ((pthread_create(&threads[i], NULL, threadFunction, (void *) &i)) != 0) {		/*	← convert the fourth parameter into a void pointer	*/
			perror(" pthread_create");
			return EXIT_FAILURE;
		}

		sleep(1);																			/*	wait a second	*/
	}

	for (i = 0; i < NBR_OF_THREADS; i++) {
		if ((pthread_join(threads[i], NULL)) != 0) {
			perror(" pthread_join");
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}
