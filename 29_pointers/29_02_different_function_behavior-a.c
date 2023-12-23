#include <stdio.h>
#include <stdlib.h>

/*	What happens, when you're using functions with at least
	one argument? A function can be called with an argument
	by value and also by reference. What's the difference
	between them?

	"call by value":
		You just want to transfer the content
		of the variable(s) to a function without
		knowing / interesting >>where<< this
		variable(s) has been stored.

	"call by reference":
		You want to use the >>address<< of an object,
		which has any content to use this in the function.
*/

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
void function2(const int *a) {
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

	/*	Are you surprised? By the way, this won't work 1:1 in C++!	*/
	function1(ex);
	function1(NULL);

	/*	This works in C, too, which doesn't work in C++.	*/
	function2(100);

	/*	normal usage of a function	*/
	function2(ex);
	function2(NULL);

	free(ex);

	return EXIT_SUCCESS;
}