/**
*	Difference between malloc() and calloc() in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct SElements {
	int value;
	char *dynamicWord;
	float *fArray;
	struct SElements *next;
};

int main() {
	/*	malloc:		"memory allocation"; allocates memory with the required size very fast. However, this function leaves the allocated
	 *				memory uninitialized. Means: you don't know where the pointers are pointing to. Maybe you're in luck, and every
	 *				pointer points to NULL.
	 *
	 *				void* malloc(size_t size); 	size = this is the size if the memory block, in bytes
	 */
	struct SElements *m_elements = (struct SElements*) malloc(sizeof(struct SElements));
	assert(m_elements != NULL);

	/*	calloc:		"clear memory allocation"; Like malloc this function allocates memory with the required size of memory, too.
	 *				Unlike malloc calloc sets allocated memory to zero, but it takes a bit longer of time for the operation.
	 *				Very useful if memory initializing is more important.
	 *
	 *				void *calloc(size_t nitems, size_t size);
	 *					nitems = the number of elements to be allocated
	 *					size = the size of elements
	 */
	struct SElements *c_elements = (struct SElements*) calloc(1, sizeof(struct SElements));
	assert(c_elements != NULL);

	printf(" malloc: value = %d | dynamicWord = %s | fArray location = %p | next = %p\n\n",
		m_elements->value, m_elements->dynamicWord, m_elements->fArray, m_elements->next);
	printf(" calloc: value = %d | dynamicWord = %s | fArray location = %p | next = %p\n",
		c_elements->value, c_elements->dynamicWord, c_elements->fArray, c_elements->next);

	free(c_elements);
	free(m_elements);
	return EXIT_SUCCESS;
}
