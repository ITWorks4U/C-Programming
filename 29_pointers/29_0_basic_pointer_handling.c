#include <stdio.h>
#include <stdlib.h>

struct Example {
	int i_member;
	char string1[100];									//	C-string with 100 bytes
	char *string2;										//	C-string with 8 bytes! (always 8 bytes, no matter, how often * is given)
};

int main(void) {
	/*
		To define a dynamic refence, you have to use a function, like malloc, calloc, realloc or valloc.
		Each function returns a void *. It's a "dynamic pointer" and can be transfered to any other
		pointer, however, make sure you know what to do.

		Be careful! Every allocated memory MUST be released by your own, before the application is going to terminate,
		otherwise memory leaks appears. In some cases it MAY ALSO AFFECT your whole machine!

		A memory leak represents a block of n bytes, which are still available, but no pointer refers to this block.

		There're different ways to allocate memory:
		-	malloc		(C/C++)
		-	calloc		(C/C++)
		-	realloc		(C/C++)
		-	valloc		(C/C++; may work, but it's not a guarantee)
		-	new			(C++ only)
		
		attention:	Unlike to C, in C++ you MUST cast it to your specified data type, because
					every function (except new) returns void*

					void* could be handled like a "unique pointer", but it's a typeless pointer

		There're two ways to releasing allocated memory:
		-	free		(C/C++)
		-	delete		(C++ only)

		------------------------------
		>>	Allocate memory of n bytes. It returns an address, where n bytes are now
		>>	available, however, you don't know, which value represents your pointer address,
		>>	depending on your used field, like int*, long*, struct Example* ptr, ...
		void *malloc(size_t __size);

		------------------------------
		>>	Acts like malloc, however, your object is initialized with a
		>>	default value, depending on the data type.
		>>	argument #0:		how many times an object needs to be allocated
		>>	argument #1:		the amount of bytes for each object
		void *calloc(size_t __nmemb, size_t __size);

		------------------------------
		>>	Reallocating more memory for an already allocated pointer.
		>>	It can also be used to allocate memory for the first time.
		>>	argument #0:		pointer to use
		>>	argument #1:		additional amount of bytes
		void *realloc(void *__ptr, size_t __size);

		------------------------------
		>>	MAY work like malloc/calloc/realloc, may also cause
		>>	an error on compile or runtime. => Hardly used.
		void *valloc(size_t __size);

		------------------------------
		>>	Releasing memory in C/C++:
		void free(void* __ptr);
		
		ATTENTION:	__ptr MUST be allocated by malloc, calloc, realloc (valloc) before,
					otherwise a segmentation fault occurs

		------------------------------
		>>	Releasing memory in C++ only:
		delete ptr;

		Even your pointer has been successfully freed/deleted from memory, your pointer
		STILL EXISTS! Assigning with NULL helps you set this pointer to NULL.

		On Linux you can use the program "valgrind", which checks, if your
		application may have memory leaks. Very useful!
	*/

	/*
		In C it's an advise, in C++ it's required to use a cast for memory allocation.
	*/
	struct Example *ex = (struct Example *) malloc(sizeof(struct Example));

	/*	Typical way to check, if "any error" appeared here.	*/
	if (ex == NULL) {
		perror("malloc()");																					//	typical way for "any error"
		return EXIT_FAILURE;
	}

	/*	Are you surprised about the wrongly size of "myStruct"?	*/
	printf("size of ex = %lu bytes <=> size of Example = %lu bytes\n", sizeof(ex), sizeof(struct Example));
	printf("location of ex: %p\n", ex);

	//	ATTENTION:	in UNIX/Linux sizeof is often defined as "unsigned long", in Windows it's often an "unsigned long long",
	//				thus the formatter %lu / %llu has to be use

	free(ex);

	return EXIT_SUCCESS;
}