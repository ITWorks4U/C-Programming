/**
*	How to use random functions in C/C++.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	time_t t;

	/*
	*	time function for a current time;	<time.h>
	*	time_t time(time_t *timer);
	*
	*	The argument *timer can also be a NULL pointer. If timer not a NULL pointer, the time, the function will store the calendar time in timer.
	*	Returning the current calendar time.
	*/
	//time(&t);
	
	/*
	*	initializing the sequence of pseudo-random numbers;		<stdlib.h>
	*	void srand(unsigned int seed);
	*
	*	The seed value of a rand()-function. The seed value determines a particular sequence of random numbers when calling the rand()-function.
	*	IMPORTANT:	If a program always uses the same seed value, then the rand()-function will always get the same sequence of numbers.
	*/
	srand(time(&t));

	/*
	*	representing a pseudo-random number;	<stdlib.h>
	*	int rand(void);
	*
	*	Returning a number between 0 and RAND_MAX (inclusive)
	*/
	int i;
	for (i = 0; i < 10; i++) {
		printf("number = %d\n", rand());
	}

	return EXIT_SUCCESS;
}
