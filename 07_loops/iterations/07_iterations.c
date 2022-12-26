#include <stdio.h>
#include <stdlib.h>

int main() {
	//	-----------
	//	for loop (stops automatically when end condition is no longer given)
	//	-----------
	/*	sequential loop	*/
	for(int i = 0; i < 10; i++) {
		printf("%d\n", i);
	}

	/*	sequential loop in reversal order	*/
	for(int i = 9; i >= 0; i--) {
		printf("%d\n", i);
	}

	/*	modifying index	*/
	for(int i = 0; i < 10; i++) {
		printf("%d\n", i++);
	}

	/*	skipping a step	*/
	for(int i = 0; i < 10; i++) {
		if (i == 5) {
			continue;
		}

		printf("%d\n", i);
	}

	/*	canceling loop	*/
	for(int i = 0; i < 10; i++) {
		if (i == 5) {
			break;
		}

		printf("%d\n", i);
	}

	//	-----------
	//	while loop (runs, while a certain condition is given)
	//	-----------
	int ctr = 0;
	while(ctr < 10) {
		ctr++;																				//	required, otherwise the loop never ends
		printf("%d\n", ctr);
	}

	//	-----------
	//	do-while loop (runs at least once)
	//	-----------
	ctr = 0;
	do {
		printf("%d\n", ctr);
		ctr++;
	} while(ctr < 10);

	return EXIT_SUCCESS;
}