#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Example {
	int i_member;
	char word1[20];
	char *word2;
};

static const char word[] = "Hello World!";

int main(void) {

	struct Example *myStruct = (struct Example *) malloc(sizeof(struct Example));
	if (myStruct == NULL) {
		fprintf(stderr, "Not enough memory!\n");
		return EXIT_FAILURE;
	}

	printf("size of myStruct = %lu bytes, location %p\n", sizeof(struct Example), myStruct);

	/*
		You can also accessing to your members, however, especially for a pointer
		inside your pointer you have to allocate it again!
	*/

	//	This works fine, unless you don't have enough free space for your C-string.
	strncpy(myStruct->word1, word, strlen(word));
	printf("word1 = %s\n", myStruct->word1);

	//	This won't. You'll receive a segemtation fault here.
	strncpy(myStruct->word2, word, strlen(word));
	printf("word2 = %s\n", myStruct->word2);

	/*
		This will fix the error above:

		>>	sizeof(char *) >>always<< returns 8 bytes only!
		>>	By adding an additional amount of bytes you can
		>>	ensure to have enough free space here.
		myStruct->word2 = (char *) malloc((sizeof(char *) + 20));

		strncpy(myStruct->word2, word, strlen(word));
		printf("word2 = %s\n", myStruct->word2);
		free(myStruct->word2);
	*/

	free(myStruct);

	return EXIT_SUCCESS;
}