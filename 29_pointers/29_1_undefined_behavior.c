#include <stdio.h>
#include <stdlib.h>

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

	//	ATTENTION #1:	This MIGHT work, but it MIGHT NOT! =>	segmentation fault
	//	ATTENTION #2:	In contrast to C in C++ this works different!
	printf("i_member: %d, string1: %s, string2: %s\n", ex->i_member, ex->string1, ex->string2);

	free(ex);

	return EXIT_SUCCESS;
}