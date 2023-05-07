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

	printf("members:\t%d, %s, %s\n", exM->i_member, exM->word1, exM->word2);

	int *i_ptr = (int *) exM;

	/*
		Pointer arithmetic works like a normal arithmetic operation, however,
		this also causes an undefined behavior. Depending on your pointer size
		you'll "walk" to the next 20 blocks with the size of your type.

		i_ptr[0] += 20 <=> points to a block of 4 bytes and this value,
		even this is NOT an integer, is going to "convert" to an integer

		i_ptr += 20 <=> similar above, however, your pointer "walks"
		to the next 20 blocks. It may work, but often, it won't.
		
		Since it's not a synthax error, your compiler won't complain that.

		You also can scan your application with valgrind!
	*/
	printf("\"i_ptr\" = %d, %p\n", i_ptr[0] += 20, i_ptr += 20);

	free(exM);

	return EXIT_SUCCESS;
}