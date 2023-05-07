#include <stdio.h>
#include <stdlib.h>

/*
	Moving an array to a function causes, that you
	really don't have a way to determine the correct
	size of this array, because a pointer always
	has a fixed size of 8 bytes!

	by the way, it makes no difference between
	int *ptr and int ************************ptr :o)
*/

void print_array(int *ptr) {
	size_t n = (sizeof(ptr) / sizeof(ptr[0]));																		//	always 2
	printf("The array has %lu elements.\n", n);

	size_t p = sizeof(ptr);																							//	always 8
	printf("The array has %lu elements.\n", p);

	size_t q = (sizeof(ptr) / sizeof(int *));																		//	always 1
	printf("The array has %lu elements.\n", q);
}

int main(void) {
	int array[] = {0,1,2,3,4,5,6,7,8,9};

	/*
		Within the context, where your array has been
		defined, you can determine the correct amount
		of elements.
	*/
	size_t n = (sizeof(array) / sizeof(array[0]));
	printf("The array has %lu elements.\n", n);

	/*	What happens, when you're using an empty array?	*/
	// int array[] = {};

	/*	Or a NULL array?	*/
	// int *array = NULL;
	print_array(array);

	return EXIT_SUCCESS;
}