#include <stdio.h>
#include <stdlib.h>

/*
	By using pointers you can directly access to the located memory to work with
	your objects, however, an undefined behavior is still a potentially risk.
	So make sure you know, what to do.

	In this example all three members of the structure is in use.
	While on Linux (in that case) all members can be accessed almost without problems,
	in Windows you might getting in trouble when you try to access to string2.

	It's a pointer, however, without allocating memory for this pointer you don't
	exactly know what's coming next. Especially by using this code in C++ with
	the typical C++ syntax.
*/

struct Example {
	int i_member;
	char string1[100];
	char *string2;
};

int main(void) {
	struct Example *ex = (struct Example *) malloc(sizeof(struct Example));

	if (ex == NULL) {
		perror("malloc()");
		return EXIT_FAILURE;
	}

	/*	You don't know what happens, when you're using string2 during runtime!

		It's an undefined behavior! It may do nothing, it could print you (null)
		(has been "worked" on Linux), a segmentation fault may appear, the next
		output could be supressed, ...
	*/
	printf("i_member: %d, string1: %s, string2: %s\n", ex->i_member, ex->string1, ex->string2);

	free(ex);

	return EXIT_SUCCESS;
}