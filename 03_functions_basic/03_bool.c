#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	In C the boolean data type doesn't exist, however, you can
	either simulate a boolean determination by using integer values,
	where 0 means false, every other value means true, by defining
	your own boolean determination or by using stdbool.h.

	In stdbool.h true is defined as 1, whereas false is defined as 0.
*/

const int number = 10;

/*	without stdbool use int instead	of bool	*/
bool value_check(int value) {
	return value > number;
}

int main() {
	printf("Is 5 greater than 10? %d\n", value_check(5));
	printf("Is 20 greater than 10? %d\n", value_check(20));

	return EXIT_SUCCESS;
}