/*
	Since at least two threads are working with a shared resource, like a shared memory,
	file, ... it's a critical section. We have to make sure, that only one thread may
	work with the resource, whereas the other threads have to wait to get the resource.

	MUTEX:	mutual exclusion
	You may also use a semaphore. => Take a look to the system programming repository instead.
	https://github.com/ITWorks4U/system-programming-C

	Attention:
		-	the behavior is different to "modern threads"
		-	since a thread blocks the resource it must be released for other threads
		-	when any error may occour within the lock, it won't be released automatically
			=> we have to do this IN THE CODE manually
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define	FILE_SOURCE "test.txt"
#define	MAX_NBR_LINES	10000
#define	MAX_CHARS		10

static pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;

void print_time(double seconds) {
	double hours = floor(seconds / 3600);
	double minutes = floor(seconds / 60);
	seconds = fmod(seconds, 60);

	if (seconds >= 60) {
		seconds = fmod(seconds, 60);
		minutes++;
	}

	if (minutes >= 60) {
		minutes = fmod(minutes, 60);
		hours++;
	}

	printf("time amount: %.lf h, %.lf min, %.lf s\n", hours, minutes, seconds);
}

void *read_file(void *) {
	/*
		trying to get the resource;
		in contrast to pthread_mutex_lock this function checks first,
		if a resource can be used at the moment

		int pthread_mutex_trylock(pthread_mutex_t *__mutex);

		returns:
		-1:	not sucessfully => errno might be set, but it hasn't an effect here
		0: sucessfully locked the resource
	*/

	while (pthread_mutex_trylock(&file_mutex) != 0) {
		puts("waiting patiently...");
		sleep(1);
	}

	FILE *source = fopen(FILE_SOURCE, "r");
	char buffer[MAX_CHARS];
	memset(buffer, '\0', sizeof(buffer));

	while ((fgets(buffer, MAX_CHARS, source)) != NULL) {
		printf("%s\n", buffer);
	}

	fclose(source);

	/*
		releasing the lock

		int pthread_mutex_unlock(pthread_mutex_t *__mutex);

		returns:
		-1: on failure => errno is set
		0: successfully released the lock
	*/
	pthread_mutex_unlock(&file_mutex);
	return NULL;
}

void *write_file(void *) {
	/*
		blocking a resource;
		in contrast to pthread_mutex_trylock() this function
		won't check, if the resource is now in use

		int pthread_mutex_lock(pthread_mutex_t *__mutex);

		returns:
		-1: on failure => errno is set
		0: resource locked
	*/
	pthread_mutex_lock(&file_mutex);

	FILE *destination = fopen(FILE_SOURCE, "w");

	for(int i = 0; i < MAX_NBR_LINES; i++) {
		fprintf(destination, "%d\n", i);
	}

	fclose(destination);

	pthread_mutex_unlock(&file_mutex);
	return NULL;
}

int main(void) {
	clock_t full_app_start = clock();
	pthread_mutex_init(&file_mutex, NULL);
	pthread_t thread1, thread2;
	
	
	if (pthread_create(&thread1, NULL, write_file, NULL) != 0) {
		perror("unable to launch first thread...");
		return EXIT_FAILURE;
	}

	if (pthread_create(&thread2, NULL, read_file, NULL) != 0) {
		perror("unable to launch second thread...");
		return EXIT_FAILURE;
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&file_mutex);
	puts("Aaaaaand done!");

	clock_t full_app_stop = clock();
	print_time(((double)(full_app_stop - full_app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}