#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	In contrast to a C-string, you can't do this
	for any other type. Try to figure out, what
	happens here.
*/

bool copy_to(int *destination, int source) {
	puts("----------------");
	puts("copy action...");
	destination = &source;
	puts("----------------");

	return true;
}


int main(void) {
	int a = 10;
	int *b = NULL;

	b = &a;
	printf("&a => %p, a = %d\n", &a, a);																//	a can be used without an error
		
	printf("b => %p, b[0] = %d\n", b, b[0]);															//	however, b won't
	// printf("b => %p, *b = %d\n", b, *b);																//	*b is "identical" to b[0]
	// printf("b => %p, b[100] = %d\n", b, b[100]);														//	you can do this, but... don't

	return EXIT_SUCCESS;
}