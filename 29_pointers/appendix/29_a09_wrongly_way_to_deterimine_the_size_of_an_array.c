#include <stdio.h>
#include <stdlib.h>

/*
	Moving an array to a function causes, that you
	really don't have a way to determine the correct
	size of this array, because a pointer always
	has a fixed size of n bytes, depending on the
	machine you're working on!

	By the way, it makes no difference between
	int *ptr and int ************************ptr :o)
*/

void print_array(int *ptr) {
	/*	for a 64 bit machine, ...	*/

	/*	n has 2	bytes	*/
	size_t n = (sizeof(ptr) / sizeof(ptr[0]));
	printf("The array has %lu elements.\n", n);

	/*	p has 8	bytes	*/
	size_t p = sizeof(ptr);
	printf("The array has %lu elements.\n", p);

	/*	q has 1	byte	*/
	size_t q = (sizeof(ptr) / sizeof(int *));
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
	printf("The array \"n\" has %lu elements.\n", n);

	/*	What happens, when you're using an empty array?	*/
	int a[] = {};
	n = (sizeof(a) / sizeof(a[0]));
	printf("The array \"a\" has %lu elements.\n", n);

	/*	Or a NULL array?	*/
	int *arrPtr = NULL;
	n = (sizeof(arrPtr) / sizeof(arrPtr[0]));
	printf("The array \"arrPtr\" has %lu elements.\n", n);

	/*	calling the function with the array(s) as argument...

		What are you expecting there?
	*/
	print_array(array);
	print_array(a);
	print_array(arrPtr);
	print_array(NULL);

	return EXIT_SUCCESS;
}