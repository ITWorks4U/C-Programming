#include <stdio.h>
#include <stdlib.h>
#include <time.h>									/*	for C	*/
// #include <ctime>									/*	for C++	*/

int main() {
	time_t t;
	srand(&t);										//	srand(1) can be used for debugging
													//	srand(NULL) is identical to srand(&t);

	/*	basicly a random number between 0 and RAND_MAX	*/
	for(int i = 0; i < 10; i++) {
		printf("random number: %d\n", rand());
	}

	/*	a random number within a range	*/
	for(int i = 0; i < 10; i++) {
		printf("random number between 10 and 100: %d\n", rand() % (100-10) + 1);
	}

	return EXIT_SUCCESS;
}