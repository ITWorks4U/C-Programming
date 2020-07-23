#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "forkTest.h"

void nonsenseFunction() {
	srand(time(NULL));
	//printf(" random number = %d\n", rand());
}

int main(int argc, char **argv) {
	int i;
	pid_t type;
	clock_t start = clock();
	printf(" Demonstration of using fork() %d times.\n", NBR_OF_FORKS);

	for (i = 0; i < NBR_OF_FORKS; i++) {
		type = fork();

		switch(type) {
			case -1:
				fprintf(stderr, " Error: %s\n", strerror(errno));
				break;
			case 0:
				nonsenseFunction();
				break;
			default: {
				switch (waitpid(type, NULL, 0)) {
					case -1:
						fprintf(stderr, " Error with waitpid(): %s\n", strerror(errno));
						return EXIT_FAILURE;
					//default:
						//printf(" Child procss terminated with exit value %d\n", WEXITSTATUS(NULL));
						
				}
			}
		}
	}

	clock_t end = clock();
	double runningTime = ((double) (end - start) / CLOCKS_PER_SEC);

	int minutes = ((int) runningTime / MINUTES);
	int seconds = ((int) runningTime % (minutes * MINUTES));

	printf(" Elapsed time for program \"%s\": %2d minutes, %2d seconds.\n", argv[0], minutes, seconds);

	return EXIT_SUCCESS;
}
