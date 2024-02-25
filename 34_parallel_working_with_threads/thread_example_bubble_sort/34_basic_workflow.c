/*
	Threads allows you to split your work into sub threads for your SINGLE process.
	Unlike to fork() to create sub processes, a single process may have n threads.

	Attention:
		In UNIX/Linux the linker needs -lm for math operations, otherwise
		your application can't be build.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "34_threads.h"

//	-------------------------------------------
//	without threads
//	-------------------------------------------
int main (void) {
	clock_t full_app_start = clock();
	puts("launching application \"without threads\"...");

	load_random_numbers();
	bubble_sort(test_array1);
	print_first_results(test_array1);

	bubble_sort(test_array2);
	print_first_results(test_array2);
	
	clock_t full_app_stop = clock();
	print_time(((double)(full_app_stop - full_app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}