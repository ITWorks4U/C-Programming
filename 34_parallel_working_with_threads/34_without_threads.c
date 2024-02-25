/*
	Working with threads.

	Threads allows you to split your work into sub threads for your SINGLE process.
	Unlike to fork() to create sub processes, a single process may have n threads.

	Attention:
		In UNIX/Linux the linker needs -lm for math operations, otherwise
		your application can't be build.

		All these examples here were built and ran under UNIX/Linux.
		There was no test on other operating systems.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#if __unix__
/*	required for sleep() => Windows uses Sleep() from windows.h*/
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

void nonsense_function(void) {
	/*	any processing here with a certain time amount	*/

	for(int i = 0; i < MAX_CTR; i++) {
		#if __WIN32__ || __WIN64__
		/*	in Windows: milliseconds are required	*/
		Sleep(1000);
		#else
		/*	in UNIX/Linux: only seconds are required	*/
		sleep(1);
		#endif
	}
}

int main(void) {
	clock_t full_app_start = clock();

	/*	without threads your application runs 200s	*/
	nonsense_function();
	nonsense_function();

	puts("Aaaand done!");
	clock_t full_app_stop = clock();
	print_time(((double)(full_app_stop - full_app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}