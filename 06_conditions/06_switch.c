#include <stdio.h>
#include <stdlib.h>

int main() {
	/*
		It may be a good option to use fgets() to read a number from keyboard,
		however, this handling has a "little" error...
	*/
	int number_level;

	printf("enter a number: ");
	scanf("%d", &number_level);

	/*	switch(expression) offers a better handling of events by given expression	*/
	switch(number_level) {
		case 0:
			//	...
			break;
		case 1:
			//	...
			break;
		case -123:
			//	...
			break;
		default:
			//	any other unmanaged case lands here
			break;
	}

	/*	weired behavior of scanf():	*/
	if (number_level) {																						//	What happens here?
		puts("This statement is \"true\"");
	} else {
		puts("This statement is \"false\"");
	}

	return EXIT_SUCCESS;
}