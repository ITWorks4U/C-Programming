/**	@author			ITWorks4U	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
#include <assert.h>

/**
*	Generating a random word by given lengh from ! to z.
*
*	param:	length
*		the length for generating string
*
*	return:
*		a random string
*/
const char *generateRandomWord(NATURAL length) {
	char *string = (char *) malloc(sizeof(char) * length);
	assert(string != NULL);

	int i, num;
	int start = (int)('!');				//	starts with number 33 (!)
	int range = (int)('z') - 32;		//	ends with number 122 (z), where all non printable characters are going to remove including space sign
	long int seconds;

	time(&seconds);
	srand(seconds);

	for (i = 0; i < length; i++) {
		num = ((rand() % range) + start);
		string[i] = (char) num;
	}

	string[length] = '\0';

	return string;
}
