/**
*	How to detect memory leaks in C
*	with the application valgrind.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct SExample Example;

struct SExample {
	unsigned int GUID;
	char *content;
	long data;
	Example **************nonsensePointerContent;	
};

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, " usage: %s <natural numeric argument1> <natural numeric argument2>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int arg1 = strtol(argv[1], NULL, 0);					/*	convert the first argument into a number						*/
	int arg2 = strtol(argv[2], NULL, 0);					/*	also convert the second argument into a number					*/
	assert(arg1 >= arg2);									/*	be sure arg1 must not be smaller than arg2						*/

	int i;
	Example *tests[arg1];									/*	let's create a set of examples									*/
	for (i = 0; i < arg1; i++) {
		printf(" creating test[%d]...\n", i);
		tests[i] = (Example *) malloc(sizeof(Example));		/*	create a new instance of tests[i]								*/
		assert(tests[i] != NULL);
	}
	
	/*	do something....	*/
	printf("\n \\|/-\\|/-\\|/-\\|/-\\|/-\\|/-\\|/-\n\n");

	for (i = (arg1 - 1); i >= (arg1 - arg2); i--) {
		printf(" removing test[%d]...\n", i);
		assert(tests[i] != NULL);							/*	remove tests[i] from memory, where arg2 may be lower than arg1	*/
		free(tests[i]);
	}

	return EXIT_SUCCESS;
}
