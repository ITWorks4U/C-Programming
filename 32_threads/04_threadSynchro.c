#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "04_threadSynchro.h"

static FILE *file = NULL;
static pthread_mutex_t fileMutex = PTHREAD_MUTEX_INITIALIZER;				/*	add a mutex	*/

void openFile(Operation op) {
	switch(op) {
		case READ_THE_FILE:
			file = fopen(FILE_TO_MODIFY, "r");
			break;
		case WRITE_THE_FILE:
			file = fopen(FILE_TO_MODIFY, "w+");
			break;
	}

	if (file == NULL) {
		perror(" fopen()");
		exit(EXIT_FAILURE);
	}
}

void closeFile() {
	assert(file != NULL);
	fclose(file);
}

void *writeIntoFile(void *arg) {
	printf(" Thread (%ld) for writing content into file \"%s\"\n", pthread_self(), FILE_TO_MODIFY);

	/*
	 *	int pthread_mutex_lock(pthread_mutex_t *__mutex)
	 *	Lock the mutex, if no other thread has locked
	 *	the mutex before.
	 *
	 *	returns:
	 *		0, if no error occurred,	
	 *		-1, otherwise
	*/
	if (pthread_mutex_lock(&fileMutex) != 0) {
		fprintf(stderr, " unable to lock mutex\n");
		exit(EXIT_FAILURE);
	}

	openFile(WRITE_THE_FILE);
	int i;
	char string[BUFFER];

	for (i = 0; i < COUNTER; i++) {
		sprintf(string, "%d\n", i);
		fputs(string, file);	

		usleep(250);											/*	let's pause the thread for 250 ms	*/
		fflush(file);
	}

	/*
	 *	int pthread_mutex_unlock (pthread_mutex_t *__mutex)
	 *	Unlock the mutex, if the current mutex is locked
	 *	and unlockable.
	 *
	 *	returns:
	 *		0, if no error occurred
	 *		-1, otherwise
	*/
	if (pthread_mutex_unlock(&fileMutex) != 0) {
		fprintf(stderr, " unable to unlock mutex\n");
		exit(EXIT_FAILURE);
	}

	closeFile();
	puts(" Writing thread is completed.");

	return NULL;
}

void *readFromFile(void *arg) {
	printf(" Thread (%ld) for reading content into file \"%s\"\n", pthread_self(), FILE_TO_MODIFY);
	int testVal;
	int currentCounter = 0;
	clock_t start = clock();

	/*
	 *	int pthread_mutex_trylock (pthread_mutex_t *__mutex)
	 *	Try to lock the current mutex. If the mutex is still
	 *	locked, then every other thread has to wait until the
	 *	locked mutex has been unlocked before.
	 *
	 *	returns:
	 *	0, if successful,
	 *	-1, otherwise
	*/
	while ((testVal = pthread_mutex_trylock(&fileMutex)) != 0) {
		fprintf(stderr, " READ: unable to lock the mutex now, because \"%s\". --- Next retry in 10 seconds.\n", strerror(testVal));
		sleep(10);
	}

	clock_t end = clock();
	double runningTime = ((double) (end - start) / CLOCKS_PER_SEC);
	int minutes = ((int) runningTime / MINUTES);
	int seconds = ((int) runningTime % (minutes * MINUTES));	
	printf(" The thread has waited %2d minutes, %2d seconds.\n", minutes, seconds);

	puts(" *** Writing thread is starting. ***");
	openFile(READ_THE_FILE);
	char string[BUFFER];

	while ((fgets(string, BUFFER, file) != NULL)) {
		if ((currentCounter % (COUNTER / 10)) == 0) {						/*	print only each 100,000th word into the console	*/
			printf(" %s", string);
		}

		currentCounter++;
	}

	if (pthread_mutex_unlock(&fileMutex) != 0) {
		fprintf(stderr, " unable to unlock mutex\n");
		exit(EXIT_FAILURE);
	}

	closeFile();
	puts(" Reading thread is completed.");

	return NULL;
}

int main(int argc, char **argv) {
	pthread_t th1, th2;
	printf(" starting main thread %ld\n", pthread_self());

	if ((pthread_create(&th1, NULL, &writeIntoFile, NULL)) != 0) {
		perror(" pthread_create()");
		exit(EXIT_FAILURE);
	}

	if ((pthread_create(&th2, NULL, &readFromFile, NULL)) != 0) {
		perror(" pthread_create()");
		exit(EXIT_FAILURE);
	}

	if ((pthread_join(th1, NULL)) != 0) {
		perror(" pthread_join()");
		exit(EXIT_FAILURE);
	}

	if ((pthread_join(th2, NULL)) != 0) {
		perror(" pthread_join()");
		exit(EXIT_FAILURE);
	}

	printf(" finishing main thread %ld\n", pthread_self());

	return EXIT_SUCCESS;
}
