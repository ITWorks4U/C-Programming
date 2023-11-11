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
	//	NULL and nullptr aren't the same!
	//	NULL is often defined as ((void *)0) or (void *) 0 or 0, whereas
	//	nullptr is a real object introduced in C++ to define "nothing",
	//	thus NULL is ALWAYS a number => integer
	//	-----------

	/*	normal usage of a function	*/
	function1(100);
	function1(NULL);
	
	/*	normal usage of a function	*/
	function2(NULL);
	function2(nullptr);

	//	-----------
	//	Won't work in C++:
	//	-----------
	//function1(ex);
	//function1(nullptr);
	//function2(100);
	//function2(ex);

	free(ex);

	return EXIT_SUCCESS;
}