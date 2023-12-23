//	required for pthread_getattr_np function
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <inttypes.h>

/*	Often misinterpreted:
	"Since a pointer is in use, it's always stored on the heap."
	That's wrong. It depends on how you use the pointer. By using
	a function like malloc(), calloc(), new, ... it's stored on the
	heap during runtime, whereas YOU MUST ensure to release this
	allocated memory by your own.

	However, a pointer can also be stored on the stack, even
	it refers to a pointer on the heap.
 */

struct S {};

int onHeap(const void *ptr) {
	/*
		We're using our own running thread to figure out,
		if the given pointer ptr is stored on the stack or heap.

		pthread_attr_getstack() checks the previously set address for a stack to
		figure out, if ptr is located on the stack or heap

		ATTENTION:	This will create pointers on runtime, which are NOT being released automatically!
	*/

	pthread_t self = pthread_self();
	pthread_attr_t attr;

	void *stack = NULL;
	size_t stacksize;
	pthread_getattr_np(self, &attr);
	pthread_attr_getstack(&attr, &stack, &stacksize);

	return ((uintptr_t) ptr >= (uintptr_t) stack && (uintptr_t) ptr < (uintptr_t) stack + stacksize);
}

int main(void) {
	int x = 100;
	int array[] = {1,2,3,4,5};
	int *ptr = calloc(5, sizeof(int));
	int *help = ptr;
	struct S s0;
	struct S *s1 = malloc(sizeof(struct S));
	struct S *s2 = NULL;

	printf("'x' has been stored on... %s\n", onHeap(&x) == 0 ? "heap" : "stack");
	printf("'array' has been stored on... %s\n", onHeap(array) == 0 ? "heap" : "stack");
	printf("'ptr' has been stored on... %s\n", onHeap(ptr) == 0 ? "heap" : "stack");
	printf("'help' has been stored on... %s\n", onHeap(help) == 0 ? "heap" : "stack");
	printf("'s0' has been stored on... %s\n", onHeap(&s0) == 0 ? "heap" : "stack");
	printf("'s1' has been stored on... %s\n", onHeap(s1) == 0 ? "heap" : "stack");
	printf("'s2' has been stored on... %s\n", onHeap(s2) == 0 ? "heap" : "stack");

	//	since s2 is NULL, it can be used for free => free(NULL) doesn't do anything
	free(s2);
	free(s1);

	//	!!! double free for free(ptr);	!!!
	//free(help);
	free(ptr);

	return EXIT_SUCCESS;
}