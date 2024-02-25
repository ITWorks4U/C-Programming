/*
	A thread may have to use arguments to work with.

	Attention:
		- by using sleep() / Sleep() a time measurment can't be handled correctly
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#if __unix__
#include <unistd.h>
#elif __WIN32__ || __WIN64__
#include <windows.h>
#endif

#define	MAX_THREADS	50

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

void *thread_function(void *arg) {
	/*
		to use your argument, you have to convert arg first;
		make sure your arg CAN be converted into a certain data type,
		otherwise an undefined behavior occurs
	*/
	int *arg_int = (int *) arg;

	/*	now you have to dereference your argument to it => first element is the way to go	*/
	int used_arg = arg_int[0];

	//	can also be used, however, it's harder to realize
	// int used_arg = *arg_int;

	printf("using this argument: %d\n", used_arg);
	return NULL;
}

int main(void) {
	clock_t full_app_start = clock();
	pthread_t threads[MAX_THREADS];
	
	for(int i = 0; i < MAX_THREADS; i++) {
		if (pthread_create(&threads[i], NULL, thread_function, (void *) &i) != 0) {
			perror("unable to launch sub thread...");
			return EXIT_FAILURE;
		}

		#if __unix__
		sleep(1);
		#elif __WIN32__ || __WIN64__
		Sleep(1000);
		#endif
	}

	for(int i = 0; i < MAX_THREADS; i++) {
		printf("collecting thread %ld\n", threads[i]);
		pthread_join(threads[i], NULL);
	}

	puts("Aaaaaand done!");

	clock_t full_app_stop = clock();
	print_time(((double)(full_app_stop - full_app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}