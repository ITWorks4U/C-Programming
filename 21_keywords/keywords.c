/**
*	How to use keywords in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keywords.h"
#include "extern/extern.h"

const char *keyWords[4] = {
	"auto",
	"static",
	"register",
	"extern"
};

int main(int argc, char **argv) {
	if (argc < 2) {
		printf(" usage: %s single_argument.\n A single_argument (without \"\") could be a: \"%s\" or \"%s\" or \"%s\" or \"%s\" only.\n",
			argv[0], keyWords[0], keyWords[1], keyWords[2], keyWords[3]);
		return EXIT_FAILURE;
	}

	int i;			

	if ((strcmp(keyWords[0], argv[1])) == 0) {						/*	user has selected "auto"		*/

	/*	---------------------------	*/
		exampleAutoKeyword();
	/*	---------------------------	*/

	} else if ((strcmp(keyWords[1], argv[1])) == 0) {				/*	user has selected "static"		*/

	/*	---------------------------	*/
		char statOpt[FIXED_NUMBER];									//	option modifier (holds "with static" | "no static")

		if ((strcmp(WITH_STATIC, argv[2])) == 0) {					//	the user want the static keyword
			strncpy(statOpt, WITH_STATIC, sizeof(WITH_STATIC));
		} else {													//	otherwise the user doesn't want the static keyword
			strncpy(statOpt, NO_STATIC, sizeof(NO_STATIC));
		}

		for (i = 0; i < MAX_LOOP_COUNT; i++) {						//	let's count the function call
			exampleStaticKeyword(statOpt);
		}
	/*	---------------------------	*/

	} else if ((strcmp(keyWords[2], argv[1])) == 0) {				/*	user has selected "register"	*/

	/*	---------------------------	*/
		exampleRegisterKeyword();
	/*	---------------------------	*/

	} else if ((strcmp(keyWords[3], argv[1])) == 0) {				/*	user has selected "extern"		*/

	/*	---------------------------	*/
		for (i = 0; i < MAX_LOOP_COUNT; i++) {
			exampleExternKeyword();
		}

		printf("\n Given function was called %d times.\n", fnctCtr);

	//	--- extern variables are still modify able from outside ---		
		fnctCtr *= 10;
		printf("\n Given function was called %d times.\n", fnctCtr);

	/*	---------------------------	*/

	} else {
		puts("Undefined valid single argument.");
	}

	return EXIT_SUCCESS;	
}
