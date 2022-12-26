#include <stdio.h>
#include <stdlib.h>
#include <time.h>									/*	for C	*/
// #include <ctime>									/*	for C++	*/
#include <stdbool.h>								/*	not required in C++	*/

int lotto_array[6];
bool already_done[6];

void lotto_number_generator(int position, int lotto_number) {
	lotto_array[position] = lotto_number;
}

int main() {
	time_t t;
	srand(time(&t));								//	srand(1) can be used for debugging
													//	srand(time(NULL)) is identical
													//	to srand(time(&t));

	for(int i = 0; i < 6; i++) {
		already_done[i] = false;
	}

	//	avoids to add a multiple number for lotto 
	int counter = 0;
	do {
		lotto_number_generator(counter, (rand() % 49) + 1);

		if (!already_done[lotto_array[counter] - 1]) {
			already_done[lotto_array[counter] - 1] = true;
			counter++;
		}
	} while (counter < 6);


	for(int i = 0; i < 6; i++) {
		printf("lotto number: %d\n", lotto_array[i]);
	}

	return EXIT_SUCCESS;
}