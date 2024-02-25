/*
	Threads allows you to split your work into sub threads for your SINGLE process.
	Unlike to fork() to create sub processes, a single process may have n threads.

	Attention:
		Usually, fork() creates a sub process to do "parallel" work, however,
		these processes won't work synchronously.
*/

#include "34_threads.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

//	-------------------------------------------
//	with sub processes
//	-------------------------------------------
int main(void) {
	clock_t full_app_start = clock();
	puts("launching application \"with sub processes\"...");
	load_random_numbers();
	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("unable to use the program...");
			return EXIT_FAILURE;
		} case 0: {
			puts("child process has been created....");
			bubble_sort(test_array1);
			print_first_results(test_array1);
			break;
		} default: {
			puts("parent process working...");
			bubble_sort(test_array2);
			print_first_results(test_array2);

			if (waitpid(pid, NULL, 0) < 0) {
				perror("unable to wait for child...");
			}

			break;
		}
	}

	clock_t full_app_stop = clock();
	print_time(((double)(full_app_stop - full_app_start) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}