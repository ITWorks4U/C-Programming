/*
	Threads allows you to split your work into sub threads for your SINGLE process.
	Unlike to fork() to create sub processes, a single process may have n threads.

	Attention:
		You need to add -lpthread for the linker to work with posix threads.
*/

#include "34_threads.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *bubble_sort_threads(void* val) {
	long *array = (long *) val;
	clock_t begin = clock();

	for(int i = 0; i < MAXIMUM - 1; i++) {
		for(int j = 0; j < MAXIMUM - i - 1; j++) {
			if (array[i] > array[j]) {
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

	print_first_results(array);
	clock_t end = clock();
	print_time(((double)(end - begin) / CLOCKS_PER_SEC));

	return NULL;
}

//	-------------------------------------------
//	with threads
//	-------------------------------------------
int main (void) {
	clock_t full_app_start = clock();
	pthread_t thread1, thread2;

	puts("launching application \"with threads\"...");
	load_random_numbers();

	if (pthread_create(&thread1, NULL, &bubble_sort_threads, &test_array1) < 0) {
		perror("pthread_create #1");
		return EXIT_FAILURE;
	}
	
	if (pthread_create(&thread2, NULL, &bubble_sort_threads, &test_array2) < 0) {
		perror("pthread_create #2");
		return EXIT_FAILURE;
	}
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	puts("........");
	puts("end of application...");
	clock_t full_app_stop = clock();
	printf("total time amount: ");
	print_time(((double)(full_app_stop - full_app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}