#include <stdio.h>
#include <stdlib.h>

struct Example {
	int i_member;
	char word1[20];																							//	C-string with 20 bytes
	char *word2;																							//	C-string with 8 bytes!
};

int main(void) {
	/*
		To define a dynamic refence, you have to use a function, like malloc, calloc, realloc or valloc.
		Each function returns a void *. It's a "dynamic pointer" and can be transfered to any other
		pointer, however, make sure you know hat to do.

		Be careful! Missing to release a pointer causes a memory leak. A memory leak also appears,
		if your memory is not marked by any pointer.

		A memory leak represents a block of n bytes, which are still available, but can no longer
		be reached by anything.

		There're four ways to allocate memory:

		>>	Allocate memory of n bytes for a structure, field or whatever.
		>>	This object, however, is uninitialized and you don't know,
		>>	what's value is set for your object.
		void *malloc(size_t __size);

		>>	Acts like malloc, however, your object is initialized with a
		>>	default value, depending on the data type.
		>>	For calloc, you have also have to set up, how many times a block
		>>	of bytes are going to reserved.
		void *calloc(size_t __nmemb, size_t __size);

		>>	Reallocating more memory for an already allocated pointer.
		void *realloc(void *__ptr, size_t __size);

		>>	>>May<< work like malloc/calloc/realloc, may also cause
		>>	an error on compile or runtime. => Hardly used.
		void *valloc(size_t __size);

		>>	Releasing memory in C:
		void free(void* __ptr);

		Even your pointer has been successfully freed from memory, your pointer
		still exists! Assigning with NULL hepls you set this pointer to NULL.

		On Linux you can use the program "valgrind", which checks, if your
		application may have memory leaks. Very useful!
	*/

	/*
		In C it's an advise, in C++ it's required to use a cast for memory allocation.
	*/
	struct Example *myStruct = (struct Example *) malloc(sizeof(struct Example));

	/*	Typical way to check, if "any error" appeared here.	*/
	if (myStruct == NULL) {
		fprintf(stderr, "Not enough memory!\n");															//	Does that always appear, when "no more memory" is left? :o)
		return EXIT_FAILURE;
	}

	printf("size of myStruct = %lu bytes, location %p\n", sizeof(myStruct), myStruct);						//	Surprised?
	printf("size of myStruct = %lu bytes, location %p\n", sizeof(struct Example), myStruct);

	free(myStruct);

	return EXIT_SUCCESS;
}