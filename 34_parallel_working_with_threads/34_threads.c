/*
	Working with threads.

	Threads allows you to split your work into sub threads for your SINGLE process.
	Unlike to fork() to create sub processes, a single process may have n threads.

	Attention:
		-	compile with: gcc [-Wall -g3] 34_threads.c -lm -lpthread -o <app_name>

		-	In UNIX/Linux the linker needs -lm for math operations, otherwise
			your application can't be build.

		-	In UNIX/Linux you also need -lpthread for the linker.

		-	Unlike to threads in C++, Python, Java, C#, ... in C we're using POSIX-threads.
			These are much more different rather than "modern thread functions" and they have
			their own bevahior. By the way, in C++ you can also use POSIX-threads, however,
			there's no guarantee, that this works fine!

		-	All these examples here were built and ran under UNIX/Linux.
			There was no test on other operating systems.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#if __unix__
/*	required for UNIX/Linux	*/
#include <unistd.h>
#else
/*	assuming you're using Windows	*/
#include <windows.h>
#endif

#define	MAX_CTR 100

/// @brief print elapsed time amount in hours, minutes and seconds
/// @param seconds time duration in seconds
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

void *nonsense_function(void *arg) {
	/*	any processing here with a certain time amount	*/

	/*
		pthread_t pthread_self()

		returns the thread-ID of the current thread
		in UNIX/Linux pthread_t is an unsigned long; in Windows / macOS / ... it could be equal
	*/
	printf("I'm thread with ID: %ld\n", pthread_self());

	for(int i = 0; i < MAX_CTR; i++) {
		#if __WIN32__ || __WIN64__
		/*	in Windows: milliseconds are required	*/
		Sleep(1000);
		#else
		/*	in UNIX/Linux: only seconds are required	*/
		sleep(1);
		#endif
	}

	/*
		Since we're using void*, a return statement is required.
		In C you might get a warning.
	*/
	return NULL;
}

int main(void) {
	clock_t app_start = clock();

	/*	using two threads to work parallel to your current application	*/
	pthread_t thread1, thread2;

	/*
		creating and automatically run your two threads now
	
		int pthread_create(
			pthrad_t *__restrict__ __newthread,
			const pthread_attr_t *__restrict__ __attr,
			void *(*__start_routine)(void*),
			void *__restrict__ __arg
		);

		__newthread: POSIX-thread to use
		__attr: if required, run this thread with certain attributes
		__start_routine: thread function to use => it must be a void* function with void* as an argument
		__arg: if required, your __start_routine uses an argument (like Object in Java / C#)

		returns:
		-1: on any error => errno is set
		0: successfully created thread, which runs NOW
	*/
	pthread_create(&thread1, NULL, nonsense_function, NULL);
	pthread_create(&thread2, NULL, nonsense_function, NULL);

	/*
		main application is forced to wait for sub threads

		int pthread_join(pthread_t __th, void **__thread_return);

		__th: thread to wait
		__thread_return: if required, the certain return value can be used for further operations

		returns:
		-1: on any error => errno is set
		0: successfully joined thread

		=> In contrast to higher languages, there's no timeout option to wait n seconds for the thread.
	*/
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	/*	Now your application needs only 100s.	*/
	puts("Aaaand done!");
	clock_t app_end = clock();
	print_time((double) ((app_end - app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}