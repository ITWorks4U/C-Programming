#include <stdio.h>
#include <stdlib.h>

/*
	There're different ways to allocate memory during runtime, like
	malloc, calloc, realloc, valloc, new, ...

	But what's the difference between these instructions?
*/

struct Example {
	int i_member;
	char word1[20];
	char *word2;
};

int main(void) {
	//	--------------------------------------
	//	malloc
	//		Since you're using malloc, your members are uninitialized on runtime!
	//		Try to figure out, what happens here. Depending on your OS, the results differs.
	//	--------------------------------------
	struct Example *exM = (struct Example *) malloc(sizeof(struct Example));
	printf("\"exM\" = %lu bytes, location %p\n", sizeof(struct Example), exM);
	printf("members:\t%d, %s, %s\n", exM->i_member, exM->word1, exM->word2);
	free(exM);

	//	--------------------------------------
	//	calloc
	//		Stands for "clean allocation". Unlike to malloc()
	//		your members are going to initialize with a fixed
	//		value, like 0 for integer types,
	//		an empty word for (C-)strings, NULL/nullptr for any pointer etc.
	//	--------------------------------------
	struct Example *exC = (struct Example *) calloc(1, sizeof(struct Example));
	printf("\"exC\" = %lu bytes, location %p\n", sizeof(struct Example), exC);
	printf("members:\t%d, %s, %s\n", exC->i_member, exC->word1, exC->word2);
	free(exC);

	//	--------------------------------------
	//	realloc
	//		Stands for reallocation memory. An already allocated memory
	//		can be expand by n additional bytes.
	//
	//		Since our structure needs 112 bytes for all members an allocation
	///		of 100 bytes only will cause an error during runtime!
	//	--------------------------------------
	exM = (struct Example *) realloc(exM, 100);
	printf("members:\t%d, %s, %s\n", exM->i_member, exM->word1, exM->word2);
	free(exM);

	//	--------------------------------------
	//	valloc
	//		page aligned memory allocating
	//		it has a similar effect like malloc(), but it's kept
	//		for historical reasons and it's also hardly used today.
	//
	//		More informations here: https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-valloc-page-aligned-memory-allocator
	//	--------------------------------------
	struct Example *exV = (struct Example *) valloc(sizeof(struct Example));
	printf("\"exV\" = %lu bytes, location %p\n", sizeof(struct Example), exV);
	printf("members:\t%d, %s, %s\n", exV->i_member, exV->word1, exV->word2);
	free(exV);
	
	return EXIT_SUCCESS;
}