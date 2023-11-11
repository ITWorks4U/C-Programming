#include <stdio.h>
#include <stdlib.h>

struct Example {
	int i_member;
	char word1[20];
	char *word2;
};

/*
	You also can define a pointer in an own function, however, by leaving
	this function your allocated memory is not going to free automatically.

	valgrind can detect such kind of memory leak
*/

void frustating_with_pointers(void) {
	struct Example *exM = (struct Example *) malloc(sizeof(struct Example));
	printf("\"exM\" = %lu bytes, location %p\n", sizeof(struct Example), exM);
	
	//	without free() your pointer is lost
	// free(exM);
}

int main(void) {
	frustating_with_pointers();

	//	outside of your function you don't have an access to your pointer
	// printf("members:\t%d, %s, %s\n", exM->i_member, exM->word1, exM->word2);

	return EXIT_SUCCESS;
}