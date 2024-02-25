/*
	Detaching a thread to make it independent can be used to do any stuff
	without waiting for this thread. However, POSIX-threads have a different
	behavior.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define	FILE_SOURCE "../random_numbers.txt"
#define MAXIMUM 250000
#define MAX_NBR_OF_THREADS	8

static long test_array[MAXIMUM];

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

void load_random_numbers(void) {
	char content_random_numbers[MAXIMUM];
	memset(content_random_numbers, '\0', sizeof(content_random_numbers));

	FILE *f = fopen(FILE_SOURCE, "r");
	while ((fgets(content_random_numbers, MAXIMUM, f)) != NULL) {}
	fclose(f);

	char delimiter[] = ", ";
	char* token = strtok(content_random_numbers, delimiter);
	int ctr = 0;

	while (token != NULL) {
		test_array[ctr] = strtol(token, NULL, 0);
		ctr++;

		token = strtok(NULL, delimiter);
	}
}

void *bubble_sort(void *arg) {
	int *max_numbers = (int *) arg;
	printf("argument = %d\n", max_numbers[0]);

	for(int i = 0; i < max_numbers[0] - 1; i++) {
		for(int j = 0; j < max_numbers[0] - i - 1; j++) {
			if (test_array[i] > test_array[j]) {
				long tmp = test_array[i];
				test_array[i] = test_array[j];
				test_array[j] = tmp;
			}
		}
	}

	return (void *) pthread_self();
}

int main(void) {
	clock_t full_app_start = clock();
	pthread_t threads[MAX_NBR_OF_THREADS];
	int args[] = {100, 2000, 10000, 800, 5000, 753, 1234, 99999};
	
	for(int i = 0; i < MAX_NBR_OF_THREADS; i++) {
		if (pthread_create(&threads[i], NULL, bubble_sort, (void *) &args[i]) != 0) {
			perror("unable to launch sub thread...");
			return EXIT_FAILURE;
		}

		if (i % 2 == 0) {
			pthread_detach(threads[i]);
			printf("thread %ld is now detached => can't be collected with pthread_join\n", threads[i]);
		}

		sleep(1);
	}

	for(int i = 0; i < MAX_NBR_OF_THREADS; i++) {
		//	POSIX-threads can also be "joined", even these are detached before
		//	not recommended to use this => undefined behavior
		// printf("collecting thread %ld\n", threads[i]);
		// pthread_join(threads[i], NULL);

		if (i % 2 != 0) {
			printf("collecting thread %ld\n", threads[i]);
			pthread_join(threads[i], NULL);
		} else {
			printf("thread %ld can't be collected...\n", threads[i]);
		}
	}

	puts("Aaaaaand done!");

	clock_t full_app_stop = clock();
	print_time(((double)(full_app_stop - full_app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}