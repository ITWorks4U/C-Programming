#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <assert.h>
#include "09_thread_condition.h"

void *threadFunction(void *arg) {
	assert(arg != NULL);
	struct SHolder *holder = (struct SHolder *) arg;

	/*	activating thread exit handler	*/
	pthread_cleanup_push(exitHandlerFunction, (void *) holder);
	printf(" Thread with ID: %ld has been started.\n", pthread_self());
	printf(" receiving data: \"%s\"\n", holder->text);

	/*	removing exit handler	*/
	pthread_cleanup_pop(1);

	return NULL;
}

void exitHandlerFunction(void *arg) {
	assert(arg != NULL);

	puts(" → Given function has been called...");

	/*	you may do something anything here...	*/

	puts(" quit function....");
}

int main(void) {
	pthread_t threads[NBR_OF_THREADS];
	int i;
	struct SHolder content[NBR_OF_THREADS];

	for (i = 0; i < NBR_OF_THREADS; i++) {
		snprintf(content[i].text, BUFFER, " I'm thread number %d.", (i+1));
		pthread_create(&threads[i], NULL, threadFunction, &content[i]);
	}

	for (i = 0; i < NBR_OF_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	return EXIT_SUCCESS;
}
