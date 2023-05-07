#include <stdio.h>
#include <stdlib.h>

struct Example {
	int i_member;
	char word1[20];
	char *word2;
};

int main(void) {
	struct Example *exM = (struct Example *) malloc(sizeof(struct Example));
	printf("\"exM\" = %lu bytes, location %p\n", sizeof(struct Example), exM);

	/*
		Using an another pointer to refer to an exising pointer causes an
		undefined behavior! Since int has a size of 4 bytes, and this
		structure has a size of 32 bytes, you're "just" using 1/8 of your
		struct.
	*/
	int *i_ptr = (int *) exM;																				//	without a cast, you'll get a warning

	free(i_ptr);																							//	You >>could<< do this...
	free(exM);																								//	...but you'll fail here!
																											//	Because i_ptr is a shallow copy to
																											//	exM, exM has already been freed above!

	return EXIT_SUCCESS;
}