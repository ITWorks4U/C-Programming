#ifndef THREADS_H
#define THREADS_H

/*	source to use	*/
#define	FILE_SOURCE "../random_numbers.txt"

/* 250,000 elements */
#define MAXIMUM 250000

//	-------------------------------------------

extern long test_array1[MAXIMUM];
extern long test_array2[MAXIMUM];

//	-------------------------------------------

void print_time(double seconds);
void load_random_numbers(void);
void bubble_sort(long *array);
void print_first_results(const long *array);

void *bubble_sort_threads(void *arg);

#endif