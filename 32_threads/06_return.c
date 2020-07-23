#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include "06_return.h"

void *threadFunction(void *arg) {
	assert(arg != NULL);
	struct SContent *tmp = (struct SContent *) arg;
	
	printf(" ID: %3d | content: %s\n", tmp->data, tmp->text);

	return tmp->data;									/*	←	ignoring the warning output		*/
}

int main(void) {
	pthread_t threads[NBR_OF_THREADS];
	struct SContent content[NBR_OF_THREADS];
	int i;
	static int retVal[NBR_OF_THREADS];

	srand(time(NULL));
	for (i = 0; i < NBR_OF_THREADS; i++) {				/*	←	starting threads				*/
		content[i].data = (rand() % 100 + i);
		snprintf(content[i].text, BUFFER, " I'm thread number %2i.", i);

		if ((pthread_create(&threads[i], NULL, threadFunction, (void *) &content[i])) != 0) {
			perror(" pthread_create");
			return EXIT_FAILURE;
		}

		//sleep(1);
	}

	for (i = 0; i < NBR_OF_THREADS; i++) {				/*	←	waiting for each thread			*/
		if ((pthread_join(threads[i], (void **) &retVal[i])) != 0) {
			perror(" pthread_join");
			return EXIT_FAILURE;
		}
	}

	puts("\n look into retVal array....\n");

	for (i = 0; i < NBR_OF_THREADS; i++) {				/*	←	print retVal[i] to the console	*/
		printf(" content of retVal[%2d] = %d\n", i, retVal[i]);
	}

	return EXIT_SUCCESS;
}
