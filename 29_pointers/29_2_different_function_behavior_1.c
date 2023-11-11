#include <stdio.h>
#include <stdlib.h>

struct Example {
	int i_member;
	char string1[100];
	char *string2;
};

/*	function call by value		*/
void function1(int a) {
	puts("function1 was called...");
}

/*	function call by reference	*/
void function2(int *a) {
	puts("function2 was called...");
}

int main(void) {
	struct Example *ex = (struct Example *) malloc(sizeof(struct Example));

	if (ex == NULL) {
		perror("malloc()");
		return EXIT_FAILURE;
	}

	//	-----------
	//	ATTENTION:
	//	In contrast to C in C++ this works different!
	//	-----------

	/*	normal usage of a function	*/
	function1(100);

	/*	Surprised?	*/
	function1(ex);
	function1(NULL);

	/*	This works in C, too.	*/
	function2(100);

	/*	normal usage of a function	*/
	function2(ex);
	function2(NULL);

	free(ex);

	return EXIT_SUCCESS;
}