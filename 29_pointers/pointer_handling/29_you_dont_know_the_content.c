#include <stdio.h>
#include <stdlib.h>

struct Example {
	int i_member;
	char word1[20];
	char *word2;
};

int main(void) {
	//	--------------------------------------
	//	malloc
	//	--------------------------------------
	struct Example *exM = (struct Example *) malloc(sizeof(struct Example));
	printf("\"exM\" = %lu bytes, location %p\n", sizeof(struct Example), exM);

	/*
		Since you're using malloc, your members are uninitialized on runtime!
		Try to figure out, what happens here.
		Depending on your OS, the results differs.
	*/
	printf("members:\t%d, %s, %s\n", exM->i_member, exM->word1, exM->word2);
	free(exM);

	//	--------------------------------------
	//	calloc
	//	--------------------------------------
	struct Example *exC = (struct Example *) calloc(1, sizeof(struct Example));
	printf("\"exC\" = %lu bytes, location %p\n", sizeof(struct Example), exC);

	printf("members:\t%d, %s, %s\n", exC->i_member, exC->word1, exC->word2);
	free(exC);

	//	--------------------------------------
	//	realloc (May cause an error here!)
	//	--------------------------------------
	exM = (struct Example *) realloc(exM, 100);
	printf("members:\t%d, %s, %s\n", exM->i_member, exM->word1, exM->word2);
	free(exM);

	//	--------------------------------------
	//	valloc
	//	--------------------------------------
	struct Example *exV = (struct Example *) valloc(sizeof(struct Example));
	printf("\"exV\" = %lu bytes, location %p\n", sizeof(struct Example), exV);

	printf("members:\t%d, %s, %s\n", exV->i_member, exV->word1, exV->word2);
	free(exV);
	
	return EXIT_SUCCESS;
}